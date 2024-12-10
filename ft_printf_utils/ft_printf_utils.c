/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 04:37:17 by ikarouat          #+#    #+#             */
/*   Updated: 2024/12/09 21:02:46 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	check_format(const char *f, va_list *ap)
{
	const char	frmt_spec;
	const char	*flags;
	int		len;

	len = 0;
	flags = get_flags(f);
	frmt_spec = *(f + ft_strlen(flags) - 1);
	if (ft_strchr(FORMATS, frmt_spec))
	{
		if (frmt_spec == 'c')
			len = check_flags(flags, va_arg(*ap, char), frmt_spec);
		if (frmt_spec == 's')
			len = check_flags(flags, va_arg(*ap, char*), frmt_spec);
		if (frmt_spec == 'p')
			len = check_flags(flags, va_arg(*ap, uintptr_t), frmt_spec);
		if (frmt_spec == 'd' || frmt_spec == 'i')
			len = check_flags(flags, va_arg(*ap, int), frmt_spec);
		if (frmt_spec == 'u')
			len = check_flags(flags, va_arg(*ap, unsigned int),frmt_spec);
		if (frmt_spec == 'x' || frmt_spec == 'X')
			len = check_flags(flags, va_arg(*ap, int), frmt_spec);
	}
	else
		break ;//handle invalid format specifier
	return (len);
}

char	*get_flags(char *f)
{
	char	*flags;
	char	*flag;
	size_t	i;

	i = 0;
	flags = ft_calloc(ft_strlen(FLAGS), sizeof(char));//to free
	while (*(f + i) && (flag = ft_strchr(FLAGS, *(f + i)))
		flags[i++] = *flag;
	return (flags);
}

int	check_flags(const char *flags, void ())
{

}

int	ft_putnbr_base(t_frmt n, unsigned int base)
{
	
}
