/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:49:13 by epalomak          #+#    #+#             */
/*   Updated: 2021/05/04 14:40:32 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	dst = (char *)malloc((sizeof(char) * len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && len > i)
		dst[i++] = s[start++];
	dst[i] = '\0';
	return (dst);
}
