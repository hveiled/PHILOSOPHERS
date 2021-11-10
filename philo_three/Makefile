# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hveiled <hveiled@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 11:45:14 by hveiled           #+#    #+#              #
#    Updated: 2021/05/22 16:29:06 by hveiled          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_three

SRC =	check_if.c \
		cleaning.c \
		create_philosofer.c \
		ft_error.c \
		main.c \
		sem_initialisation.c \
		parser.c \
		routine.c \
		time.c \
		utilites.c
		

CC = gcc -Wall -Werror -Wextra -lpthread

all:$(NAME)

$(NAME):$(SRC)
		$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

PHONY: all clean fclean re
