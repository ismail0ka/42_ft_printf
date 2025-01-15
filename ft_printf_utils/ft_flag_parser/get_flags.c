/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:59:02 by ikarouat          #+#    #+#             */
/*   Updated: 2025/01/15 15:59:08 by ikarouat         ###   ########.fr       */
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
void	set_flag(const char c, t_frmt_ctx *frmt_ctx)
{
	if (c == '+')
		frmt_ctx->plus_flag = 1;
	else if (c == '-')
		frmt_ctx->minus_flag = 1;
	else if (c == '0')
		frmt_ctx->zero_flag = 1;
	else if (c == '#')
		frmt_ctx->hash_flag = 1;
	else if (c == ' ')
		frmt_ctx->space_flag = 1;
}

void	get_flags(const char **s, t_frmt_ctx *frmt_ctx)
{
	while (**s && !is_format_specifier(**s))
	{
		while (is_valid_flag(**s))
		{
			set_flag(**s, frmt_ctx);
			(*s)++;
		}
		while (ft_isdigit(**s))
		{
			frmt_ctx->width += ((**s) - '0') * 10;
			(*s)++;
		}
		if (*s == '.')
		{
			frmt_ctx->has_precision = 1;
			frmt_ctx->precision = get_precision(++(*s));
		}
		(*s)++;
	}
}
