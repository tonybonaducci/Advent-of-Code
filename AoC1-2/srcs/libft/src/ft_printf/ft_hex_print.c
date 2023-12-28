/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:58:44 by rmenezes          #+#    #+#             */
/*   Updated: 2023/11/01 17:00:21 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static unsigned int	hex_num_len(unsigned int num)
{
	unsigned int	len;
	unsigned int	nb;

	nb = num;
	len = 0;
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

static void	ft_put_hex(t_print *tab, char *str, char *hex, unsigned int num)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		str[i++] = hex[num % 16];
		num /= 16;
	}
	str[i] = '\0';
	ft_putstr_fd(ft_strrev(str), 1);
	tab -> tl += ft_strlen(str);
}

void	print_hex(t_print *tab, const char n)
{
	char			*hex_base;
	char			*str;
	unsigned int	num;

	num = va_arg(tab->args, unsigned int);
	if (num == 0)
	{
		tab ->tl += write(1, "0", 1);
		return ;
	}
	str = malloc(hex_num_len(num) + 1);
	if (!str)
	{
		tab -> tl += write(1, "(null)", 6);
		return ;
	}
	if (n == 'X')
		hex_base = "0123456789ABCDEF";
	else
		hex_base = "0123456789abcdef";
	ft_put_hex(tab, str, hex_base, num);
	free (str);
}
