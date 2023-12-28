/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:41:50 by rmenezes          #+#    #+#             */
/*   Updated: 2023/04/20 14:15:49 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	end;
	unsigned int	s;

	i = 0;
	end = ft_strlen(dest);
	s = ft_strlen((char *)src);
	if (size == 0)
		return (s);
	if (size < end)
		s += size;
	else
		s += end;
	while (src[i] != '\0' && (end + i) < size -1)
	{
		dest[end + i] = src[i];
		i++;
	}
	dest[end + i] = '\0';
	return (s);
}
