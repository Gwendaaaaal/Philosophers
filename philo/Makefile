# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gholloco <gwendal.hollocou@orange.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 21:58:52 by gholloco          #+#    #+#              #
#    Updated: 2024/04/30 22:04:19 by gholloco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SOURCES = main.c parse.c utils.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -g -fsanitize=thread -Wall -Werror -Wextra -pthread

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
