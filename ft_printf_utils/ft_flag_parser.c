/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:17:03 by ikarouat          #+#    #+#             */
/*   Updated: 2024/12/23 03:04:33 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_flag_parser.h"

static char	is_valid_flag(const char c)
{
	const char	*valid_flags;

	valid_flags = "+-0# .";
	while (*valid_flags)
	{
		if (*valid_flags == c)
			return (1);
		valid_flags++;
	}
	return (0);
}

char	is_format_specifier(const char c)
{
	const char	*format_specifiers;

	format_specifiers = "diuxXpcs";
	while (*format_specifiers)
	{
		if (*format_specifier == c)
			return (1);
		format_specifiers++;
	}
	return (0);
}

static unsigned int	get_precision(const char **s)
{
	unsigned int	res;

	res = 0;
	while (**s && ft_isdigit(**s))
	{
		res *= 10;
		res += ((**s) - '0');
		(*s)++;
	}
	return (res);
}

static const char	*append_flag(const char *flags, const char c)
{
	const char	*new_flags;
	size_t		i;

	if (!flags)
	{
		flags = ft_calloc(2, sizeof(char));
		if (!flags)
			return (NULL);
		*flags = c;
		return (flags);
	}
	i = 0;
	new_flags = ft_calloc(ft_strlen(flags) + 2, sizeof(char));
	if (!new_flags)
		return (NULL);
	while (flags[i])
		new_flags[i] = flags[i++];
	new_flags[i] = c;
	free(flags);
	return (new_flags);
}

static void	init_flags_context(t_flags_ctx *flags_ctx)
{
	flags_ctx->flags = NULL;
	flags_ctx->flags_offset = 0;
	flags_ctx->has_precision = 0;
	flags_ctx->precision = -1;
}

static void	set_frmt_flag(t_frmt_ctx *frmt_ctx, const char f, const char v)
{
	if (!v)
		return ;
	if (f == '0')
		frmt_ctx->zero_flag = v - '0';
	else if (f == '-')
		frmt_ctx->minus_flag = v - '0';
	else if (f == ' ')
		frmt_ctx->space_flag = v - '0';
	else if (f == '+')
		frmt_ctx->plus_flag = v - '0';
	else if (f == '#')
		frmt_ctx->hash_flag = v - '0';
	else 
		return ;
}

t_flags_ctx	get_flags(const char *s, t_frmt_ctx *frmt_ctx)
{
	t_flags	flags_ctx;
	size_t	initial_len;

	initial_len = ft_strlen(s);
	flags_ctx = init_flags_context(&flags_ctx);
	while (*s && !is_format_specifier(*s))
	{
		if (is_valid_flag(*s))
		{
			set_frmt_flag(frmt_ctx, *s, *(s + 1));
			flags_ctx->flags = append_flag(flags_ctx->flags, *s);
			if (*s == '.')
			{
				flags.has_precision = 1;
				flags.precision = get_precision(&(++s));
			}
		}
		s++;
	}
	flags_ctx->flags_offset = initial_len - ft_strlen(s);
	return (flags_ctx);
}
