/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmax_toa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:54:29 by epalomak          #+#    #+#             */
/*   Updated: 2021/05/04 15:39:47 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

static int	ft_nb_count(intmax_t nb)
{
	long	c;

	c = 0;
	if (nb < 0)
		nb = nb * -1;
	while (nb >= 10)
	{
		nb = nb / 10;
		c++;
	}
	return (c + 1);
}

char	*ft_intmax_itoa(intmax_t n)
{
	intmax_t	i;
	char		*dst;

	i = ft_nb_count(n);
	dst = ft_strnew(i + 1);
	if (n < 0)
	{
		dst[0] = '-';
		n = -n;
	}
	else
		i--;
	if (n == 0)
		dst[0] = '0';
	while (n > 0)
	{
		dst[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (dst);
}
