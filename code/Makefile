# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/05 18:22:35 by logkoege          #+#    #+#              #
#    Updated: 2025/04/10 23:58:24 by logkoege         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
MLX = -L./minilibx-linux -lmlx -lX11 -lXext -lm
INCLUDES = -I./minilibx-linux -I.

SRC =	exec/main.c\
		exec/utils.c\
		exec/mlx_utils.c\
		exec/move.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re