/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 03:13:42 by ikarouat          #+#    #+#             */
/*   Updated: 2025/01/21 17:30:33 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static size_t	ft_nbrlen(int n, unsigned int base)
{
    size_t	len;

    len = 1;
    while (n >= (int)base)
    {
        n /= base;
        len++;
    }
    return (len);
}

char	*ft_putnbr_base(int n, const char *base)
{
    size_t        n_len;
	unsigned int        base_len;
    char          *str;
    
    base_len = ft_strlen(base);
    n_len = ft_nbrlen(n, base_len);
    str = malloc(n_len + 1);
    if (!str)
        return (NULL);
    str[n_len] = '\0';
    if (n < 0)
    {
        str[0] = '-';
        n = -n;
    }
    if (n == 0)
        str[0] = '0';
    while (n > 0)
    {
        str[--n_len] = base[n % base_len];
        n /= base_len;
    }
    return (str);
}
