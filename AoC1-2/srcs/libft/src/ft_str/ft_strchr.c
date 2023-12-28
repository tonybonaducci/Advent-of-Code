/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:03:57 by rmenezes          #+#    #+#             */
/*   Updated: 2023/04/20 12:04:03 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *str, int c)
{
	unsigned char	ch;

	if (!str)
		return (0);
	ch = (unsigned char)c;
	while (*str != '\0' && *str != ch)
		str++;
	if (*str == ch)
		return ((char *)str);
	return (0);
}
