/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:49:36 by epalomak          #+#    #+#             */
/*   Updated: 2021/05/04 14:45:13 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	st;
	size_t	i;
	int		ac;

	str = (char **)malloc(sizeof(char *) * ft_count(s, c) + 1);
	if (!str)
		return (NULL);
	ac = -1;
	i = 0;
	while (++ac < ft_count(s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		st = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i] == '\0' && s[i - 1] == c)
			break ;
		str[ac] = ft_strsub(s, st, i - st);
		i++;
	}
	str[ac] = NULL;
	return (str);
}
