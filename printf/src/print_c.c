/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:41:04 by epalomak          #+#    #+#             */
/*   Updated: 2020/01/29 13:35:59 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

void	print_c(t_tags *tags)
{
	int		count;
	char	c;

	count = 0;
	c = (char)va_arg(tags->arg, int);
	if (tags->flags[2] == '-')
		write(1, &c, 1);
	if (tags->width != 0)
	{
		while (++count < tags->width)
			write(1, &tags->flags[0], 1);
		if (tags->flags[2] != '-')
			write(1, &c, 1);
		count--;
	}
	else
		write(1, &c, 1);
	tags->count += count + 1;
}
