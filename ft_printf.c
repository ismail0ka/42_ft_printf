/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:45:20 by ikarouat          #+#    #+#             */
/*   Updated: 2024/11/22 16:15:24 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf(const char *s, ...)
{
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
	va_list	args;

	va_start(args, s);
	
	va_end(args);
	return ;
}
