/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:14:08 by epalomak          #+#    #+#             */
/*   Updated: 2021/05/04 14:21:49 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	if (s2[0] == '\0')
		return ((char *)s1);
	j = 0;
	while (s1[j] != '\0' && len > 0)
	{
		i = 0;
		if (s1[j] == s2[i])
		{
			while (s2[i] != '\0' && s1[j + i] == s2[i] && len > i)
			{
				i++;
				if (s2[i] == '\0')
					return ((char *)&s1[j]);
			}
		}
		j++;
		len--;
	}
	return (NULL);
}
