/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:12:43 by rmenezes          #+#    #+#             */
/*   Updated: 2023/05/10 11:39:40 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	str_count(char const *s, char c)
{
	int	i;
	int	j;
	int	booli;

	i = 0;
	j = 0;
	booli = 0;
	while (s[i])
	{
		if (s[i] != c && booli == 0)
		{
			j++;
			booli = 1;
		}
		if (s[i] == c)
			booli = 0;
		i++;
	}
	return (j);
}

static char	*split_sub(char const *s, unsigned int start, size_t end)
{
	char	*res;
	size_t	i;
	size_t	len;

	len = end - start;
	i = 0;
	if (!s)
		return (0);
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (0);
	while (i < len)
	{
		res[i] = s[start];
		start ++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		start;
	int		count;
	int		end;

	start = 0;
	i = 0;
	end = 0;
	count = str_count(s, c);
	res = malloc(sizeof(char *) * (count + 1));
	while (i < count)
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		res[i++] = split_sub(s, start, end);
		start = end;
	}
	if (!res)
		return (0);
	res[i] = NULL;
	return (res);
}
