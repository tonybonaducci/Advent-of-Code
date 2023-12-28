/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:13:52 by rmenezes          #+#    #+#             */
/*   Updated: 2023/04/20 15:27:58 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*to_add;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	to_add = ft_lstlast(*lst);
	to_add ->next = new;
}
