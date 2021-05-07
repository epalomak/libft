/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:17:51 by epalomak          #+#    #+#             */
/*   Updated: 2021/05/04 15:14:11 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft.h"

typedef struct s_tags
{
	char			flags[5];
	int				preci;
	size_t			i;
	int				negative;
	char			minus;
	int				width;
	char			*length;
	va_list			arg;
	int				upp;
	int				count;
	char			dot;
	int				org_strl;
	char			plus;
	struct s_tags	*next;
}					t_tags;

int					ft_printf(const char *formt, ...);
int					display_width(t_tags *tags, char *str, int count);
int					ft_unb_count(uintmax_t nb);

t_tags				*check_tags(char *str, t_tags *tags);
t_tags				*tap_flags(char *str, t_tags *tags);

void				print_c(t_tags *tags);
void				print_s(t_tags *tags);
void				print_p(t_tags *tags);
void				print_d(t_tags *tags);
void				print_o(t_tags *tags);
void				print_x(t_tags *tags);
void				print_u(t_tags *tags);
void				print_f(t_tags *tags);
void				print_special(t_tags *tags);
void				ft_display(t_tags *tags, char *str);

char				*ft_intmax_itoa_base(intmax_t src, int base, int uppercase);
char				*ft_uintmax_itoa_base(uintmax_t src, int base,
						int uppercase);
char				*ft_itoa_base(int src, int base, int uppercase);
char				*ft_uintmax_itoa(uintmax_t n);
char				*ft_intmax_itoa(intmax_t n);
char				*ft_ftoa(long double src, int preci);
char				*ft_join_free(char *s1, char *s2);

#endif
