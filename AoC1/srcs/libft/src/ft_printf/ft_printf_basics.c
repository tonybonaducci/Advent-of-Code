/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_basics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:58:55 by rmenezes          #+#    #+#             */
/*   Updated: 2023/11/01 17:00:38 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	nb_print(t_print *tab, const char n)
{
	char	*str;

	if (n == 'u')
		str = ft_uitoa(va_arg(tab->args, unsigned int));
	else
		str = ft_itoa(va_arg(tab->args, int));
	if (!str)
		tab -> tl += write(1, "(null)", 6);
	ft_putstr_fd(str, 1);
	tab -> tl += ft_strlen(str);
	free (str);
}

void	char_print(t_print *tab)
{
	char	a;

	a = va_arg(tab->args, int);
	write(1, &a, 1);
	tab -> tl++;
}

void	str_print(t_print *tab)
{
	char	*str;

	str = va_arg(tab->args, char *);
	if (!str)
	{
		tab -> tl += write(1, "(null)", 6);
		return ;
	}
	tab->tl += write(1, str, ft_strlen(str));
}
