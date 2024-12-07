/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 04:37:17 by ikarouat          #+#    #+#             */
/*   Updated: 2024/12/06 21:55:34 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	check_format(char *f, t_frmt arg)
{
	char	frmt_spec;
	char	*flags;

	flags = check_flags(f);
	frmt_spec = f + ft_strlen(flags) - 1;
}

char	*check_flags(char *f)
{
	char	*flags;
	char	*flag;
	size_t	i;

	i = 0;
	flags = ft_calloc(6, sizeof(char));//to free
	while (*(f + i) && (flag = ft_strchr(FLAGS, *(f + i)))
		flags[i++] = *flag;
	return (flags);
}

t_frmt	ft_putnbr_base(t_frmt n, unsigned int base)
{
	
}

t_frmt	ft_putstr(t_frmt s)
{

}

char	*ft_strchr(const char *s, int c)
{

}
