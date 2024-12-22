/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:30:48 by ikarouat          #+#    #+#             */
/*   Updated: 2024/12/21 06:30:26 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	init_format_context(t_frmt_ctx *frmt_ctx, t_flags_ctx flags_ctx)
{
	frmt_ctx->has_zero_flag = 0;
	frmt_ctx->has_minus_flag = 0;
	frmt_ctx->has_space_flag = 0;
	frmt_ctx->has_plus_flag = 0;
	frmt_ctx->has_hash_flag = 0;
	frmt_ctx->precision = -1;
	if (ft_strchr(flags_ctx.flags, '0'))
		frmt_ctx->has_zero_flag = 1;
	if (ft_strchr(flags_ctx.flags, '-'))
		frmt_ctx->has_minus_flag = 1;
	if (ft_strchr(flags_ctx.flags, ' '))
		frmt_ctx->has_space_flag = 1;
	if (ft_strchr(flags_ctx.flags, '+'))
		frmt_ctx->has_plus_flag = 1;
	if (ft_strchr(flags_ctx.flags, '#'))
		frmt_ctx->has_hash_flag = 1;
	if (flags_ctx->has_precision)
		frmt_ctx->precision = flags_ctx.precision;
	frmt_ctx->buffer = NULL;
	frmt_ctx->buffer_len = 0;
}

const char	*check_format_specifier(const char *s, va_list *ap_p)
{
	char		frmt_spec;
	const char	*buffer;

	frmt_spec = *(s + ft_strlen(flags) - 1);
	if (ft_strchr("di", frmt_spec))
		buffer = ft_putnbr_base(va_arg(*ap_p, (int)), 10);
	else if (ft_strchr("u", frmt_spec))
		buffer = ft_putnbr_base(va_arg(*ap_p, (unsigned int)), 10);
	else if (ft_strchr("xX", frmt_spec))
		buffer = ft_putnbr_base(va_arg(*ap_p, (int)), 16);
	else if (ft_strchr("p", frmt_spec))
		buffer = ft_putptr(va_arg(*ap_p, (uintptr_t)));
	else if (ft_strchr("cs", frmt_spec))
		buffer = ft_putstr(va_arg(*ap_p, (char *)));
	else
		break ;
}

int	handle_arg(const char *s, va_list *ap_p)
{
	//Set flags for the context
	t_frmt_ctx	frmt_ctx;
	t_flags_ctx	flags;

	flags = get_flags(s);
	if (!flags)
		return (0);
	//Get the buffer
	//Apply the set flags
	init_format_context(&frmt_ctx, flags);
	frmt_ctx.buffer = check_format_specifier(s, ap_p);
	frmt_ctx.buffer_len = ft_strlen(frmt_ctx.buffer);
	return (len);
}
