/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:57:20 by epalomak          #+#    #+#             */
/*   Updated: 2021/05/07 14:49:24 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

static	long double	get_nbr(t_tags *tags, long double nbr)
{
	if (ft_strcmp(tags->length, "L") == 0)
		nbr = va_arg(tags->arg, long double);
	else
		nbr = va_arg(tags->arg, double);
	return ((long double)nbr);
}

static	char	*check_rest_flags(char *str, t_tags *tags)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dst = ft_strnew(ft_strlen(str) + 1);
	if (tags->flags[4] == ' ' && tags->minus != '-' && tags->flags[0] != '0'
		&& tags->plus != '+')
		dst[i++] = ' ';
	if (tags->flags[3] == '+' && tags->negative != -1 && tags->flags[0] != '0')
	{
		dst[i++] = '+';
		tags->flags[3] = '0';
	}
	while (str[j] != '\0')
		dst[i++] = str[j++];
	free(str);
	return (dst);
}

static	long double	ft_round_nbr(t_tags *tags, long double nbr)
{
	long double	i;
	int			count;

	if (tags->dot != '.')
		tags->preci = 6;
	i = 0.500;
	count = tags->preci;
	if (tags->dot == 1 && tags->preci == 0)
		count = 0;
	while (count > 0 && count--)
		i /= 10;
	if (nbr < 0)
	{
		i *= -1;
		tags->minus = '-';
	}
	nbr += i;
	return (nbr);
}

void	print_f(t_tags *tags)
{
	long double		src;
	char			*str;
	int				count;

	src = get_nbr(tags, 0);
	src = ft_round_nbr(tags, src);
	if (tags->preci == 0 && tags->dot == '.')
	{
		str = ft_intmax_itoa((intmax_t)src);
		if (tags->minus == '-' && str[0] == '0')
			str = ft_join_free("-", str);
		if (tags->flags[1] == '#')
			str = ft_join_free(str, ".");
	}
	else
		str = ft_ftoa(src, tags->preci);
	str = check_rest_flags(str, tags);
	count = ft_strlen(str);
	if (tags->flags[2] == '-')
		ft_display(tags, str);
	if (tags->width != 0)
		count = display_width(tags, str, count);
	else if (tags->flags[2] != '-')
		ft_display(tags, str);
	tags->count += count;
}
