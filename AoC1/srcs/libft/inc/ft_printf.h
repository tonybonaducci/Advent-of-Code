/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:59:25 by rmenezes          #+#    #+#             */
/*   Updated: 2023/11/01 17:18:25 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_print
{
	va_list	args;
	int		tl;
}	t_print;

void	str_print(t_print *tab);
void	char_print(t_print *tab);
void	nb_print(t_print *tab, const char n);
void	ft_print_ptr(t_print *tab);
void	print_hex(t_print *tab, const char n);
char	*ft_uitoa(unsigned int n);
char	*ft_strrev(char *str);
int		ft_printf(const char *format, ...);

#endif
