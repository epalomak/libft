/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:29:22 by epalomak          #+#    #+#             */
/*   Updated: 2021/05/07 14:49:56 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

static	uintmax_t	get_nbr(t_tags *tags, uintmax_t nbr)
{
	if (ft_strcmp(tags->length, "hh") == 0)
		nbr = (unsigned char)(va_arg(tags->arg, int));
	if (ft_strcmp(tags->length, "h") == 0)
		nbr = (unsigned short)(va_arg(tags->arg, int));
	if (ft_strcmp(tags->length, "ll") == 0)
		nbr = (unsigned long long)(va_arg(tags->arg, long long int));
	if (ft_strcmp(tags->length, "l") == 0)
		nbr = (unsigned long)(va_arg(tags->arg, unsigned long int));
	if (ft_strcmp(tags->length, "\0") == 0)
		nbr = va_arg(tags->arg, unsigned int);
	return ((uintmax_t)nbr);
}

static	char	*zero_str(t_tags *tags, int count)
{
	char	*dst;
	int		i;
	char	h;

	i = 0;
	if (tags->upp == 1)
		h = 'X';
	else
		h = 'x';
	dst = ft_strnew(tags->preci - count + 1);
	if (tags->negative == -1)
	{
		dst[i++] = '-';
		tags->negative = 1;
	}
	if (tags->flags[1] == '#')
	{
		dst[i++] = '0';
		dst[i++] = h;
	}
	while (count++ < tags->preci)
		dst[i++] = '0';
	return (dst);
}

static	char	*create_str(uintmax_t src, t_tags *tags)
{
	char	*dst;
	char	*hash;

	if (tags->upp == 1)
		hash = "0X";
	else
		hash = "0x";
	if (src < 0)
	{
		tags->negative = -1;
		src *= -1;
	}
	if (tags->preci == 0 || tags->preci < ft_unb_count(src))
	{
		dst = ft_uintmax_itoa_base(src, 16, tags->upp);
		if (tags->flags[1] == '#' && ft_strcmp(dst, "0")
			&& tags->flags[0] != '0')
			dst = ft_join_free(hash, dst);
		return (dst);
	}
	tags->flags[0] = ' ';
	dst = ft_uintmax_itoa_base(src, 16, tags->upp);
	return (dst);
}

static int	if_width(t_tags *tags, char *str, int count)
{
	if (tags->preci != 0)
		tags->flags[0] = ' ';
	if (tags->flags[1] == '#' && tags->flags[0] == '0')
	{
		if (tags->upp == 1)
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
		count += 2;
	}
	while (count++ < tags->width)
		write(1, &tags->flags[0], 1);
	if (tags->flags[2] != '-')
		ft_display(tags, str);
	count--;
	return (count);
}

void	print_x(t_tags *tags)
{
	int			count;
	uintmax_t	nbr;
	char		*str;

	nbr = get_nbr(tags, 0);
	str = create_str(nbr, tags);
	if (tags->dot == '.' && tags->preci == 0)
		ft_strclr(str);
	if (tags->preci != 0 && tags->preci > (int)ft_strlen(str))
		str = ft_join_free(zero_str(tags, ft_strlen(str)), str);
	count = ft_strlen(str);
	if (tags->flags[2] == '-')
		ft_display(tags, str);
	if (tags->width != 0)
		count = if_width(tags, str, count);
	else if (tags->flags[2] != '-')
		ft_display(tags, str);
	tags->count += count;
}
