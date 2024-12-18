/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:35:51 by ikarouat          #+#    #+#             */
/*   Updated: 2024/12/14 02:10:04 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_flag_parser.h"
typedef struct s_frmt_ctx
{
	char		has_zero_flag;//if minus flag is set unset zero
	char		has_minus_flag;
	char		has_hash_flag;
	char		has_space_flag;
	char		has_plus_flag;
	size_t		precision;
	const char	*buffer;
	size_t		buffer_len;
} t_frmt_ctx;
int		handle_arg(const char *s, va_list *ap_p);
const char	*check_format_specifier(const char *s)
#endif //FT_PRINTF_UTILS_H
