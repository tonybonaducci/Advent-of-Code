/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:59:33 by rmenezes          #+#    #+#             */
/*   Updated: 2023/11/01 17:29:40 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

static void	ft_put_ptr(uintptr_t num, char *str)
{
	char	*hex_base;
	int		i;

	hex_base = "0123456789abcdef";
	i = 0;
	while (num > 0)
	{
		str[i++] = hex_base[num % 16];
		num /= 16;
	}
	str[i] = '\0';
	ft_putstr_fd(ft_strrev(str), 1);
}

void	ft_print_ptr(t_print *tab)
{
	unsigned long int	ptr;
	char				*str;

	ptr = va_arg(tab->args, unsigned long);
	if (ptr == 0)
	{
		tab->tl += write(1, "(nil)", 5);
		return ;
	}
	tab->tl += write(1, "0x", 2);
	str = malloc (sizeof(char) * ft_ptr_len(ptr) + 1);
	if (!str)
	{
		tab -> tl += write(1, "(null)", 6);
		return ;
	}
	ft_put_ptr(ptr, str);
	tab->tl += ft_ptr_len(ptr);
	free (str);
}
