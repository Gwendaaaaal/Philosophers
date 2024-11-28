# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gholloco <gwendal.hollocou@orange.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 21:58:52 by gholloco          #+#    #+#              #
#    Updated: 2024/11/28 15:26:40 by gholloco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SOURCES = actions.c exit.c init.c main.c monitor.c parse.c philo.c utils.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -g -Wall -Werror -Wextra

RMFLAGS = -rf

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm $(RMFLAGS) $(OBJECTS)

fclean : clean
	rm $(RMFLAGS) $(NAME)

re : fclean all

PHONY = all clean fclean re
