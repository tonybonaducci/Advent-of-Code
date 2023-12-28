/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:07:16 by rmenezes          #+#    #+#             */
/*   Updated: 2023/04/20 18:50:27 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	srclen;

	i = 0;
	j = 0;
	srclen = ft_strlen(s);
	if (!s)
		return (0);
	if (start > srclen)
	{
		start = 0;
		len = 0;
	}
	if (start + len > srclen)
		len = srclen - start;
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (0);
	i = start;
	while (i < srclen && j < len)
		res[j++] = s[i++];
	res[j] = '\0';
	return (res);
}
