/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:35:51 by ikarouat          #+#    #+#             */
/*   Updated: 2024/12/23 03:22:58 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_flag_parser.h"
typedef struct s_frmt_ctx
{
	char		zero_flag;
	char		minus_flag;
	char		hash_flag;
	char		space_flag;
	char		plus_flag;
	size_t		precision;
	const char	*buffer;
	size_t		buffer_len;
} t_frmt_ctx;
int		handle_arg(const char *s, va_list *ap_p);
const char	*ft_putnbr_base(int n, const char *base);
const char	*ft_put_unsigned_nbr(unsigned int n);
const char	*ft_putptr(uintptr_t);
int		ft_putchar(const char c);
int		ft_putstr(const char *s);
#endif //FT_PRINTF_UTILS_H
