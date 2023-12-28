# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmenezes <rmenezes@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 22:53:24 by rmenezes          #+#    #+#              #
#    Updated: 2023/12/27 23:56:32 by rmenezes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

NAME = day1

SRC = main.c

OBJ = $(SRC:.c=.o)

all: deps $(NAME)

deps:
	$(MAKE) -C ./libft

$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re: fclean all