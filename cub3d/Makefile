# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/20 14:30:35 by sashin            #+#    #+#              #
#    Updated: 2021/06/08 19:22:15 by sashin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3d

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -lz
MLX				= -L./mlx -lmlx -framework OpenGL -framework AppKit

SRCS			= cub3d.c \
				check_files.c \
				parse.c \
				map_check.c \
				map_tools.c \
				draw.c \
				ray.c \
				ray_tools.c \
				control.c \
				error.c \
				tools.c

SRCS_DIR		= srcs

LIBS			= lib_sashin.a
LIBS_DIR		= lib

INCLUDES		= includes

all: $(NAME)

$(NAME): $(addprefix $(SRCS_DIR)/, $(SRCS))
	make -C $(LIBS_DIR)
	$(CC) $(CFLAGS) $(MLX) $^ $(addprefix $(LIBS_DIR)/, $(LIBS)) -o $(NAME)

clean:
	make clean -C $(LIBS_DIR)

fclean: clean
	make fclean -C $(LIBS_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re