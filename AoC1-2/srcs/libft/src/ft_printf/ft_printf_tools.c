/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:59:06 by rmenezes          #+#    #+#             */
/*   Updated: 2023/11/01 17:16:50 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
char	*ft_strrev(char *str)
{
	int			len;
	int			i;
	char		tmp;

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
*/
static int	ft_numlen(unsigned int n)
{
	int				len;
	unsigned int	i;

	len = 0;
	i = n;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char			*str;
	int				i;
	int				len;
	unsigned int	nbr;

	i = 0;
	nbr = n;
	len = ft_numlen(nbr);
	str = malloc(sizeof(int) * len + 1);
	if (!str)
		return (NULL);
	if (nbr == 0)
		str[i++] = 48;
	while (nbr > 0)
	{
		str[i++] = (nbr % 10) + 48;
		nbr /= 10;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
