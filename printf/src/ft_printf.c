/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:35:29 by epalomak          #+#    #+#             */
/*   Updated: 2021/05/04 15:34:00 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

static void	set_tags(t_tags *tags)
{
	tags->flags[0] = ' ';
	tags->flags[1] = '\0';
	tags->flags[2] = '\0';
	tags->flags[3] = '\0';
	tags->flags[4] = '\0';
	tags->preci = 0;
	tags->negative = 1;
	tags->length = "\0";
	tags->width = 0;
	tags->upp = 0;
	tags->dot = '\0';
	tags->minus = '0';
	tags->plus = '0';
}

static void	go_through(t_tags *tags, const char *formt)
{
	while (formt[tags->i])
	{
		if (formt[tags->i] != '%')
		{
			ft_putchar(formt[tags->i]);
			tags->count++;
		}
		if (formt[tags->i] == '%')
		{
			if (!formt[tags->i + 1])
				break ;
			set_tags(tags);
			if (check_tags((char *)formt, tags) == 0)
				break ;
		}
		tags->i++;
	}
}

int	ft_printf(const char *formt, ...)
{
	t_tags		*tags;

	tags = (t_tags *)malloc(sizeof(t_tags));
	if (!tags)
		return (0);
	tags->i = 0;
	tags->count = 0;
	va_start(tags->arg, formt);
	go_through(tags, formt);
	va_end(tags->arg);
	free(tags);
	return (tags->count);
}
