/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:25:15 by epalomak          #+#    #+#             */
/*   Updated: 2021/05/04 17:09:43 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

t_tags	*tap_flags(char *str, t_tags *tags)
{
	if (str[tags->i] == '0')
		tags->flags[0] = '0';
	if (str[tags->i] == '#')
		tags->flags[1] = '#';
	if (str[tags->i] == '-')
		tags->flags[2] = '-';
	if (str[tags->i] == '+')
		tags->flags[3] = '+';
	if (str[tags->i] == ' ')
		tags->flags[4] = ' ';
	return (tags);
}

static int	neg_plus(t_tags *tags, int count)
{
	if ((tags->negative == -1 || tags->flags[3] == '+'))
	{
		if (tags->negative != -1 && tags->flags[0] == '0' && tags->preci == 0)
		{
			write(1, "+", 1);
			tags->plus = '+';
		}
		else if (tags->flags[0] == '0' && tags->minus != '-'
			&& (tags->preci > tags->org_strl || tags->preci == 0))
		{
			write(1, "-", 1);
			tags->minus = '-';
		}
		if (tags->preci <= tags->org_strl || tags->preci == 0)
			count++;
	}
	return (count);
}

int	display_width(t_tags *tags, char *str, int count)
{
	count = neg_plus(tags, count);
	while (count++ < (tags->width))
	{
		if (tags->flags[4] == ' ')
		{
			write(1, " ", 1);
			tags->flags[4] = '\0';
			count++;
		}
		if (tags->preci != 0 && tags->preci < tags->width)
			tags->flags[0] = ' ';
		write(1, &tags->flags[0], 1);
	}
	if (tags->flags[2] != '-')
		ft_display(tags, str);
	count--;
	return (count);
}

void	ft_display(t_tags *tags, char *str)
{
	if (tags->negative == -1 && tags->minus != '-')
	{
		write(1, "-", 1);
		if (tags->width == 0)
			tags->count++;
	}
	ft_putstr(str);
	free(str);
}

char	*ft_join_free(char *s1, char *s2)
{
	char	*dst;

	dst = ft_strjoin(s1, s2);
	if (!dst)
		return (0);
	if (ft_strcmp(s1, "-") != 0 && ft_strcmp(s1, "0x") != 0
		&& ft_strcmp(s1, "0X") != 0)
		free(s1);
	if (ft_strcmp(s2, ".") != 0)
		free(s2);
	return (dst);
}
