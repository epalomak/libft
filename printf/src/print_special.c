/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_special.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:38:59 by epalomak          #+#    #+#             */
/*   Updated: 2021/05/07 14:48:39 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

void	print_special(t_tags *tags)
{
	int		count;
	char	c;

	count = 0;
	c = '%';
	if (tags->flags[2] == '-')
		write(1, &c, 1);
	if (tags->width != 0)
	{
		while (++count < tags->width)
			write(1, &tags->flags[0], 1);
		if (tags->flags[2] != '-')
			write(1, &c, 1);
	}
	else
		write(1, &c, 1);
	if (count == 0)
		count++;
	tags->count += count;
}
