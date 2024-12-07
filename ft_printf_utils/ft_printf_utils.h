/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 04:37:47 by ikarouat          #+#    #+#             */
/*   Updated: 2024/12/08 00:16:44 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# ifndef FLAGS
#  define FLAGS "-0.# +"
# endif
# ifndef FORMATS
#  define FORMATS "cspdiuxX"
# endif

typedef unsigned int	t_uint;
typedef union u_frmt	t_frmt;
union	u_frmt
{
	uintptr_t	p;
	t_uint		u;
	char		c;
	char		*s;
	int			xdi;
};
int		check_format(const char *f, va_list *ap);
int		check_flags(const char *f);
char	*ft_strchr(const char *s, int c);
t_frmt	ft_putnbr_base(t_frmt n, unsigned int base);
t_frmt	ft_putstr(char *s);
#endif
