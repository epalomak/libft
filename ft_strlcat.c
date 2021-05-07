/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:35:50 by epalomak          #+#    #+#             */
/*   Updated: 2021/05/04 14:31:40 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	size;
	size_t	res;
	size_t	i;

	size = ft_strlen(dst);
	res = ft_strlen(src);
	if (dstsize <= size)
		return (res + dstsize);
	else
		res = res + size;
	i = 0;
	while (src[i] != '\0' && dstsize > size + 1)
		dst[size++] = src[i++];
	dst[size] = '\0';
	return (res);
}
