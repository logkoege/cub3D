# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/05 18:22:35 by logkoege          #+#    #+#              #
#    Updated: 2025/05/21 09:18:03 by lloginov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3  -fsanitize=address
MLX = -L./minilibx-linux -lmlx -lX11 -lXext -lm
INCLUDES = -I./minilibx-linux -I.

SRC =	gnl/get_next_line.c\
		gnl/get_next_line_utils.c\
		parsing/main.c\
		parsing/utils.c\
		parsing/utils2.c\
		parsing/utils3.c\
		parsing/parsing.c\
		parsing/check_files.c\
		parsing/walls_utils.c\
		parsing/color_check.c\
		parsing/ft_spliter.c\
		parsing/roof_color_check.c\
		parsing/floor_parser.c\
		parsing/color_utils.c\
		parsing/map_assign.c\
		parsing/check_map.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

# $(MLX)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re