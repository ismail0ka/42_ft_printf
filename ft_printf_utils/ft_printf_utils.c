/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:30:48 by ikarouat          #+#    #+#             */
/*   Updated: 2024/12/14 02:11:59 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

const char	*check_format_specifier(const char *s)
{
	
}

int	handle_arg(const char *s, va_list *ap_p)
{
	t_frmt_ctx	frmt_ctx;

	if (init_format_context(&frmt_ctx))
	{
		check_flags(s, &frmt_ctx);
		frmt_ctx.buffer = check_format_specifier(s);
		frmt_ctx.buffer_len = ft_strlen(frmt_ctx.buffer);
		return (len);
	}
}
