/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parser.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:11:10 by ikarouat          #+#    #+#             */
/*   Updated: 2024/12/14 01:14:04 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLAG_PARSER_H
# define FT_FLAG_PARSER_H

typedef (*t_flag_handler)(char *, char);
typedef struct s_flag
{
	char		flag;
	t_flag_handler	flag_handler;
} t_flag;

#endif //FT_FLAG_PARSER_H
