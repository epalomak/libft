/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:57:07 by epalomak          #+#    #+#             */
/*   Updated: 2019/11/26 12:16:13 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strtrim(char const *s)
{
	size_t			i;
	size_t			l;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return (ft_strdup(s + i));
	l = ft_strlen(s) - 1;
	while ((s[l] == ' ' || s[l] == '\t' || s[l] == '\n') && l > 0)
		l--;
	return (ft_strsub(s, i, (l - i + 1)));
}
