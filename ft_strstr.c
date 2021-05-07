/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:25:32 by epalomak          #+#    #+#             */
/*   Updated: 2021/05/04 14:17:42 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	x;

	x = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[x] != '\0')
	{
		i = 0;
		if (s1[x] == s2[i])
		{
			while (s2[i] != '\0' && s1[x + i] == s2[i])
				i++;
			if (s2[i] == '\0')
				return ((char *)&s1[x]);
		}
		x++;
	}
	return (NULL);
}
