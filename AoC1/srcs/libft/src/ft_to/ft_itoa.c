/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:13:42 by rmenezes          #+#    #+#             */
/*   Updated: 2023/11/01 17:19:41 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strrev(char *str)
{
	int		len;
	int		i;
	char	tmp;

	len = 0;
	i = 0;
	while (str[len])
		len++;
	len -= 1;
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}

static int	get_num_len(unsigned int nb, int n)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	if (n < 0)
		return (i + 1);
	return (i);
}

static size_t	conv_neg(int n)
{
	size_t	nb;

	if (n < 0)
	{
		if (n == -2147483648)
			nb = 2147483648;
		else
			nb = n * -1;
	}
	else
		nb = n;
	return (nb);
}

char	*ft_itoa(int n)
{
	char			*ret;
	int				i;
	int				len;
	size_t			nb;

	i = 0;
	nb = conv_neg(n);
	len = get_num_len(nb, n);
	ret = malloc(sizeof(char) * len + 1);
	if (!ret)
		return (0);
	if (n == 0)
		ret[i++] = 48;
	while (nb > 0)
	{
		ret[i++] = nb % 10 + 48;
		nb /= 10;
	}
	if (n < 0)
		ret[i++] = '-';
	ret[i] = '\0';
	return (ft_strrev(ret));
}
