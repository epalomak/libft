/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:18:52 by epalomak          #+#    #+#             */
/*   Updated: 2021/05/04 15:15:41 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

static	t_tags	*check_specifier(char *str, t_tags *tags)
{
	if (str[tags->i] == 'c')
		print_c(tags);
	else if (str[tags->i] == 's')
		print_s(tags);
	else if (str[tags->i] == 'p')
		print_p(tags);
	else if (str[tags->i] == 'd' || str[tags->i] == 'i')
		print_d(tags);
	else if (str[tags->i] == 'o')
		print_o(tags);
	else if (str[tags->i] == 'u')
		print_u(tags);
	else if (str[tags->i] == 'x' || str[tags->i] == 'X')
	{
		if (str[tags->i] == 'X')
			tags->upp = 1;
		print_x(tags);
	}
	else if (str[tags->i] == 'f')
		print_f(tags);
	else if (str[tags->i] == '%')
		print_special(tags);
	else
		return (0);
	return (tags);
}

static	t_tags	*check_length(char *str, t_tags *tags)
{
	if (str[tags->i] == 'h' && str[tags->i + 1] == 'h')
	{
		tags->length = "hh";
		tags->i += 2;
	}
	else if (str[tags->i] == 'l' && str[tags->i + 1] == 'l')
	{
		tags->length = "ll";
		tags->i += 2;
	}
	else if (str[tags->i] == 'l')
		tags->length = "l";
	else if (str[tags->i] == 'L')
		tags->length = "L";
	else if (str[tags->i] == 'h')
		tags->length = "h";
	if (str[tags->i] == 'h' || str[tags->i] == 'l' || str[tags->i] == 'L')
		tags->i++;
	if (!(str[tags->i]))
		return (0);
	return (check_specifier(str, tags));
}

static int	get_nbr(char *str, t_tags *tags)
{
	int		nbr;

	nbr = 0;
	while (str[tags->i] >= '0' && str[tags->i] <= '9' && str[tags->i] != '\0')
	{
		nbr = nbr * 10 + str[tags->i] - '0';
		tags->i++;
	}
	return (nbr);
}

static	t_tags	*check_width_preci(char *str, t_tags *tags)
{
	if (str[tags->i] >= '0' && str[tags->i] <= '9')
		tags->width = get_nbr(str, tags);
	while (str[tags->i] >= '0' && str[tags->i] <= '9')
		tags->i++;
	if (str[tags->i] == '.')
	{
		tags->i++;
		tags->dot = '.';
		tags->preci = get_nbr(str, tags);
	}
	while (str[tags->i] >= '0' && str[tags->i] <= '9')
		tags->i++;
	if (!(str[tags->i]))
		return (0);
	return (check_length(str, tags));
}

t_tags	*check_tags(char *str, t_tags *tags)
{
	tags->i++;
	while (str[tags->i] == '0' || str[tags->i] == '-' || str[tags->i] == '+'
		|| str[tags->i] == '#' || str[tags->i] == ' ')
	{
		tap_flags(str, tags);
		tags->i++;
	}
	if (tags->flags[2] == '-')
		tags->flags[0] = ' ';
	return (check_width_preci(str, tags));
}
