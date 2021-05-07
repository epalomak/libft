/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:48:48 by epalomak          #+#    #+#             */
/*   Updated: 2021/05/04 14:13:32 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dst;
	int				i;

	dst = b;
	i = 0;
	while (len > 0)
	{
		dst[i++] = (unsigned char)c;
		len--;
	}
	return ((void *)dst);
}
