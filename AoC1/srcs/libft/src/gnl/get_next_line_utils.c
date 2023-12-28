/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:48:56 by rmenezes          #+#    #+#             */
/*   Updated: 2023/12/27 22:32:23 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlenG(char *str)
{
	size_t	n;

	if (!str)
		return (0);
	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

char	*ft_strjoinG(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	ret = malloc(sizeof(char) * (ft_strlenG(s1) + ft_strlenG(s2)) + 1);
	if (!ret)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			ret[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
		ret[i++] = s2[j++];
	ret[i] = '\0';
	free (s1);
	return (ret);
}

char	*ft_strchrG(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return (&str[ft_strlenG(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return (&str[i]);
		i++;
	}
	return (0);
}
