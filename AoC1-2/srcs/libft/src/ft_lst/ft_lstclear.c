/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:26:11 by rmenezes          #+#    #+#             */
/*   Updated: 2023/04/20 15:27:16 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*xl;

	if (!*lst)
		return ;
	while (*lst)
	{
		xl = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = xl;
	}
	*lst = 0;
}
