/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:37:01 by rmenezes          #+#    #+#             */
/*   Updated: 2023/04/20 17:52:37 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	prod;
	void	*p;

	prod = size * nitems;
	p = malloc(prod);
	if (!p)
		return (0);
	ft_memset(p, 0, prod);
	return (p);
}
