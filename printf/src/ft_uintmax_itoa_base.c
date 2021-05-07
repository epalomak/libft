/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmax_itoa_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:48:34 by epalomak          #+#    #+#             */
/*   Updated: 2021/05/07 17:50:57 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

static	int	ft_un_ncount(uintmax_t nb, int base)
{
	size_t	c;

	c = 0;
	if (nb < 0)
	{
		c++;
		nb = -nb;
	}
	while (nb)
	{
		nb /= base;
		c++;
	}
	return (c);
}

static	char	*check_upper(int uppercase)
{
	char	*base_tab;

	if (uppercase == 1)
		base_tab = "0123456789ABCDEF";
	else
		base_tab = "0123456789abcdef";
	return (base_tab);
}

char	*ft_uintmax_itoa_base(uintmax_t src, int base, int uppercase)
{
	char		*base_tab;
	char		*dst;
	uintmax_t	i;

	i = ft_un_ncount(src, base);
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (base < 2 || base > 16 || !dst)
		return (0);
	base_tab = check_upper(uppercase);
	dst[i--] = '\0';
	if (src < 0)
	{
		src = -src;
		dst[0] = '-';
	}
	if (src == 0)
		dst[0] = '0';
	while (src)
	{
		dst[i--] = base_tab[src % base];
		src /= base;
	}
	return (dst);
}
