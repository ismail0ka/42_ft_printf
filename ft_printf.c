/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:45:20 by ikarouat          #+#    #+#             */
/*   Updated: 2024/12/06 03:54:16 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf(const char *s, ...)
{
	frmt_u	frmt_spec;
	va_list	ap;

	va_start(ap, s);
	while (*(s + 1) && s)
	{
		if (*s++ == '%')
			check_format(s, check_flags(s));
	}
	va_end(ap);
	return ;
}
//check s for first occurence of %
//check flags '-0.' && '# +'
//check format_specifier in (cspdiuxX%)
//flag 0n applies to n in (diuxX) pad left with n zeros
//flag -n (overrides flag 0) pad right with blanks
//flag .n shows n bytes from value
//flag #n applies to n in (xX) prefixes res with 0x or 0X
//flag ' 'n leaves a blank before positive numbers (or empty string)
//produced by a signed conversion
//flag +n applies to (di) a + or - sign should always appear before n
