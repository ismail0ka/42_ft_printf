/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:30:48 by ikarouat          #+#    #+#             */
/*   Updated: 2025/01/16 17:01:32 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	init_format_context(t_frmt_ctx *frmt_ctx)
{
	frmt_ctx->zero_flag = -1;
	frmt_ctx->minus_flag = -1;
	frmt_ctx->space_flag = -1;
	frmt_ctx->plus_flag = -1;
	frmt_ctx->hash_flag = -1;
	frmt_ctx->width = 0;
	frmt_ctx->has_precision = 0;
	frmt_ctx->precision = -1;
	frmt_ctx->buffer = NULL;
	frmt_ctx->buffer_len = 0;
}

const char	*check_format_specifier(const char **s, va_list *ap_p)
{
	const char	*buffer;

	if (**s == 'd' || **s == 'i')
		buffer = ft_getnbr_base(va_arg(*ap_p, (int)), "0123456789");
	else if (**s == 'u')
		buffer = ft_get_unsigned_nbr(va_arg(*ap_p, (unsigned int)));
	else if (**s == 'x')
		buffer = ft_getnbr_base(va_arg(*ap_p, (int)), "0123456789abcdef");
	else if (**s == 'X')
		buffer = ft_getnbr_base(va_arg(*ap_p, (int)), "0123456789ABCDEF");
	else if (**s == 'p')
		buffer = ft_getptr(va_arg(*ap_p, (uintptr_t)));
	else if (**s == 's')
		buffer = va_arg(*ap_p, (char *));
	else if (**s == 'c')
		buffer = va_arg(*ap_p, (char));
	else
		return (NULL);
	return (buffer);
}

int	handle_arg(const char **s, va_list *ap_p)
{
	t_frmt_ctx	frmt_ctx;

	frmt_ctx = malloc(sizeof(t_frmt_ctx));
	init_format_context(&frmt_ctx);
	get_flags(s, &frmt_ctx);
	frmt_ctx.buffer = check_format_specifier(*s, ap_p);
	frmt_ctx.buffer_len = ft_strlen(frmt_ctx.buffer);
	return (apply_flags_and_write(&frmt_ctx));
}
