/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:12:57 by epalomak          #+#    #+#             */
/*   Updated: 2021/05/04 15:20:22 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

char	*ft_first_part(intmax_t src2, long double src)
{
	char	*dst;

	dst = ft_intmax_itoa(src2);
	if (src < 0 && ft_strcmp("0", dst) == 0)
		dst = ft_join_free("-", dst);
	return (dst);
}

char	*ft_ftoa(long double src, int preci)
{
	int			i;
	char		*dst1;
	char		*dst2;
	char		*final;
	intmax_t	src2;

	src2 = (intmax_t)src;
	dst1 = ft_first_part(src2, src);
	if (src < 0)
		src *= -1;
	if (src2 < 0)
		src2 *= -1;
	i = 0;
	dst2 = ft_strnew(preci + 2);
	dst2[i++] = '.';
	while (preci-- > 0)
	{
		src = (src - (long double)src2) * 10;
		src2 = (intmax_t)src;
		dst2[i++] = src2 + '0';
	}
	final = ft_strjoin(dst1, dst2);
	free(dst1);
	free(dst2);
	return (final);
}
