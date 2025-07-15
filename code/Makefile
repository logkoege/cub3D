# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/05 18:22:35 by logkoege          #+#    #+#              #
#    Updated: 2025/07/15 19:49:31 by logkoege         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Werror -Wall -Wextra -g3 -fsanitize=address
MLX = -L./minilibx-linux -lmlx -lX11 -lXext -lm
INCLUDES = -I./minilibx-linux -I.

SRC =	exec/main.c\
		exec/utils.c\
		exec/mlx_utils.c\
		exec/move.c\
		exec/draw.c\
		exec/utils2.c\
		exec/ray.c\
		exec/draw_player.c\
		exec/minimap.c\
		exec/texture.c\

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
