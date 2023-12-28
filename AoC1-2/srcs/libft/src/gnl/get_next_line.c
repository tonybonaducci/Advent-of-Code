/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:30:31 by rmenezes          #+#    #+#             */
/*   Updated: 2023/12/27 22:32:30 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*read_call(char *stash, int fd)
{
	char	*buff;
	int		bytes_read;

	bytes_read = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!ft_strchrG(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			free (stash);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		stash = ft_strjoinG(stash, buff);
	}
	free (buff);
	if (!stash)
		return (NULL);
	return (stash);
}

char	*stash_to_line(char *stash, char *ret)
{
	int	i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	ret = malloc(sizeof(char) * i + 2);
	if (!ret)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		ret[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		ret[i] = stash[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*repeat_call(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	j = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\0')
	{	
		free (stash);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * ft_strlenG(stash) - i + 1);
	if (!new_stash)
		return (NULL);
	i++;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free (stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*ret;

	ret = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_call(stash, fd);
	if (!stash)
		return (NULL);
	if (!stash[0])
	{
		free(stash);
		stash = NULL;
	}
	ret = stash_to_line(stash, ret);
	stash = repeat_call(stash);
	return (ret);
}

/*
int	main(void)
{
	const char *filename = "empty";
	int flags = O_RDONLY;
	int fd = open(filename, flags);
	int i = 0;
	char *next;

	while (i < 25)
	{
		next = get_next_line(fd);
		printf("line %d:%s:", i, next);
		free (next);
		i++;
	}
	close (fd);
}
*/

