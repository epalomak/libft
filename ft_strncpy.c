/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:43:51 by epalomak          #+#    #+#             */
/*   Updated: 2021/05/04 14:26:40 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (len > i && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (len != 0)
	{
		while (len > i)
		{
			dst[i] = '\0';
			i++;
		}
	}
	return (dst);
}
