/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:59:14 by rmenezes          #+#    #+#             */
/*   Updated: 2023/11/01 17:29:59 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_print	*ft_initialise_tab(t_print *tab)
{
	tab->tl = 0;
	return (tab);
}

int	print_cond(t_print *tab, const char *format, int i)
{
	if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
		nb_print(tab, format[i]);
	if (format[i] == 'c')
		char_print(tab);
	if (format[i] == 's')
		str_print(tab);
	if (format[i] == 'x' || format [i] == 'X')
		print_hex(tab, format[i]);
	if (format[i] == 'p')
		ft_print_ptr(tab);
	if (format[i] == '%')
		tab -> tl += write(1, "%", 1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	t_print		*tab;
	int			i;
	int			res;

	i = 0;
	res = 0;
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab -> args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i = print_cond(tab, format, i + 1);
		else
			res += write(1, &format[i], 1);
		i++;
	}
	va_end(tab->args);
	res += tab -> tl;
	free (tab);
	return (res);
}
