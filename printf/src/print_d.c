/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:48:31 by epalomak          #+#    #+#             */
/*   Updated: 2021/05/07 14:21:55 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

static	intmax_t	get_nbr(t_tags *tags, intmax_t nbr)
{
	if (ft_strcmp(tags->length, "hh") == 0)
		nbr = (signed char)(va_arg(tags->arg, int));
	if (ft_strcmp(tags->length, "h") == 0)
		nbr = (short)(va_arg(tags->arg, int));
	if (ft_strcmp(tags->length, "ll") == 0)
		nbr = (long long)(va_arg(tags->arg, long long int));
	if (ft_strcmp(tags->length, "l") == 0)
		nbr = (long)(va_arg(tags->arg, long int));
	if (ft_strcmp(tags->length, "\0") == 0)
		nbr = va_arg(tags->arg, int);
	return ((intmax_t)nbr);
}

static	char	*check_rest_flags(char *str, t_tags *tags)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dst = ft_strnew(ft_strlen(str) + 1);
	if (tags->flags[4] == ' ' && tags->negative != -1 && tags->flags[0] != '0'
		&& tags->plus != '+' && tags->flags[3] != '+')
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

static	char	*create_str(intmax_t src, t_tags *tags)
{
	char	*dst;

	if (src < 0)
	{
		src *= -1;
		tags->negative = -1;
	}
	dst = ft_uintmax_itoa(src);
	return (dst);
}

static	char	*zero_str(t_tags *tags, int count)
{
	char	*dst;
	int		i;

	i = 0;
	dst = ft_strnew(tags->preci - count + 1);
	if (tags->flags[3] == '+' && tags->negative != -1)
	{
		dst[i++] = '+';
		tags->plus = '+';
		tags->flags[3] = '\0';
	}
	if (tags->negative == -1)
	{
		dst[i++] = '-';
		tags->minus = '-';
	}
	while (count++ < tags->preci)
		dst[i++] = '0';
	return (dst);
}

void	print_d(t_tags *tags)
{
	int			count;
	intmax_t	nbr;
	char		*str;
	char		*p;

	nbr = get_nbr(tags, 0);
	str = create_str(nbr, tags);
	tags->org_strl = (int)ft_strlen(str);
	if (tags->dot == '.' && tags->preci == 0 && str[0] == '0')
		ft_strclr(str);
	if (tags->preci != 0 && tags->preci > (int)ft_strlen(str))
	{
		p = zero_str(tags, ft_strlen(str));
		str = ft_join_free(p, str);
	}
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
