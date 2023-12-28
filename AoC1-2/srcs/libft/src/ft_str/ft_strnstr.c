/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:48:46 by rmenezes          #+#    #+#             */
/*   Updated: 2023/04/19 17:07:55 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (little[0] == '\0')
		return ((char *) big);
	while (i < len && big[i])
	{
		j = 0;
		k = i;
		while (little[j] && big[k] == little [j] && k < len)
		{
			j++;
			k++;
		}
		if (little[j] == '\0')
			return ((char *) &big[i]);
		i++;
	}
	return (0);
}
