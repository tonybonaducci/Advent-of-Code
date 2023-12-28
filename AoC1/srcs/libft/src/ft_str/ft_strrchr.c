/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:55:47 by rmenezes          #+#    #+#             */
/*   Updated: 2023/04/20 11:59:55 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	ch;
	int				i;

	if (!str)
		return (0);
	i = 0;
	ch = (unsigned char)c;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	while (*str != ch && i != 0)
	{
		str--;
		i--;
	}
	if (*str == ch)
		return ((char *) str);
	return (0);
}
