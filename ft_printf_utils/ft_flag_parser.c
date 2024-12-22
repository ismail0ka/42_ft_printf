/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:17:03 by ikarouat          #+#    #+#             */
/*   Updated: 2024/12/22 04:45:16 by ikarouat         ###   ########.fr       */
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
	while (ft_isdigit(**s))
	{
		res *= 10;
		res += ((**s) - '0');
		(*s)++;
	}
	return (res);
}

static const char	*append_flag(const char *flags, const char c)
{
	if (!flags)
	{
		flags = ft_calloc(2, sizeof(char));//to_free
		if (!flags)
			return (NULL);
		*flags = c;
		return (flags);
	}
	//TO DO
}

static void	init_flags_context(t_flags_ctx *flags_ctx)
{
	flags_ctx->flags = NULL;
	flags_ctx->flags_offset = 0;
	flags_ctx->has_precision = 0;
	flags_ctx->precision = -1;
}

t_flags_ctx	get_flags(const char *s)
{
	t_flags	flags_ctx;

	flags_ctx = init_flags_context(&flags_ctx);
	while (*s && !is_format_specifier(*s))
	{
		if (is_valid_flag(*s))
		{
			if (*s == '.')
			{
				flags.has_precision = 1;
				flags.precision = get_precision(&(++s));
			}
			flags_ctx->flags = append_flag(flags_ctx->flags, *s);
		}
	}
}
