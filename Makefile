# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anakin <anakin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 01:48:16 by anakin            #+#    #+#              #
#    Updated: 2024/11/03 03:29:56 by anakin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
MINILIBX = minilibx/libmlx.a
GNL = $(wildcard get_next_line/*.c)
SRCS = $(wildcard src/*.c) $(GNL)
CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./Includes
OBJS = $(SRCS:.c=.o)
FRAMEWORK = -Lminilibx -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME): $(MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(FRAMEWORK)

$(MINILIBX):
	make -C minilibx

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)
	make clean -C minilibx

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

