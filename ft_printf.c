/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:45:20 by ikarouat          #+#    #+#             */
/*   Updated: 2025/01/16 19:13:12 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list		ap;
	int			len;
	char		*buffer;

	len = 0;
	buffer = NULL;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
			len += handle_format(++s , &ap, buffer);
		else
			len += ft_putchar(*s);
		s++;
	}
	va_end(ap);
	if (buffer)
		free(buffer);
	return (len);
}
