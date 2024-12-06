/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:05:12 by ikarouat          #+#    #+#             */
/*   Updated: 2024/12/06 03:49:23 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
#include "printf_utils/printf_utils.h"

union frmt_u{
	char		c;
	char		*s;
	uintptr_t	p;
	int		xdi;
	unsigned int	u;
}
typedef union frmt_u frmt_u;
int	ft_printf(const char *s, ...);
#endif
