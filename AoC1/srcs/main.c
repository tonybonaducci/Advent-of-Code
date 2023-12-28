/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:21:27 by rmenezes          #+#    #+#             */
/*   Updated: 2023/12/27 22:45:25 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/inc/libft.h"

/*
typedef struct s_digits
{
	int num_first;
	int num_last;
	char digit_first;
	char digit_last;
}	t_digits;
*/


char get_last_digit(char *str)
{
	int i;
	i = strlen(str);
	char c;
	while (ft_isdigit(str[i]) == 0)
	{
		i--;
	}
	c = str[i];
	return (c);
}

char get_first_digit(char *str)
{
	int i;
	char c;
	
	i = 0;
	while(ft_isdigit(str[i]) == 0)	
	{
		i++;
	}
	c = str[i];
	return (c);
}
char *get_digits(char *str)
{
	char *nbrs;

	nbrs = malloc(3);
	nbrs[0] = get_first_digit(str);
	nbrs[1] = get_last_digit(str);
	nbrs[2] = '\0';
	return (nbrs);
}

int	main (void)
{
	const char *filename = "cal_doc";
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

/*
	{
		if (ft_isdigit(str[i]) == 0)
			i++;
		else
			nbrs[j++] = str[i++];
	}
	if (j == 1)
	{
		nbrs[1] = nbrs[0];
	}

*/