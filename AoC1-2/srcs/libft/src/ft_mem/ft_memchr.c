/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:26:11 by rmenezes          #+#    #+#             */
/*   Updated: 2023/04/13 12:50:26 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	ch;
	size_t			i;

	s = (unsigned char *) str;
	ch = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (s[i] == ch)
			return (&s[i]);
		i++;
	}
	return (0);
}
