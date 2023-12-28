/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:21:27 by rmenezes          #+#    #+#             */
/*   Updated: 2023/12/28 01:42:51 by rmenezes         ###   ########.fr       */
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


int get_digits(char *str)
{
	char a;
	char b;
	int res;

	a = get_first_digit(str);
	b =  get_last_digit(str);
	res = atoi(a);
	res *= 10;
	res += atoi(b);
	return (res);
}

void parse_str(char *str)
{
	int i;
	int j;

	i = 0;
	while(str[i])
	{
		while (ft_isdigit(str[i]) == 0 || !ft_strnstr(str, "one", i))

	}

}

int	main (void)
{
	const char *filename = "cal_doc.txt";
	int flags = O_RDONLY;
	int fd = open(filename, flags);
	int i = 0;
	int sum = 0;
	char *next;
	char *digits;

	while (i < 1000)
	{
		next = get_next_line(fd);
		printf("line %d:%s:", i, next);
		digits = get_digits(next);
		printf("line %d 's digits: %s \n", i, digits);
		sum += atoi(digits);
		printf("current sum : %d\n", sum);
		free (next);
		free (digits);
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