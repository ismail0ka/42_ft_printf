/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parser.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:11:10 by ikarouat          #+#    #+#             */
/*   Updated: 2024/12/22 04:19:44 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLAG_PARSER_H
# define FT_FLAG_PARSER_H
# include "libft_utils.h"

typedef struct s_flags_ctx
{
	const char	*flags;
	unsigned int	flags_offset;
	int		has_precision;
	int	precision;
} t_flags_ctx;

t_flags_ctx	get_flags(const char *s);

#endif //FT_FLAG_PARSER_H
