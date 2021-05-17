# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/20 14:30:35 by sashin            #+#    #+#              #
#    Updated: 2021/05/17 19:31:17 by sashin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3d

CC				= gcc
CFLAGS			= -L./mlx -lmlx -framework OpenGL -framework AppKit

SRCS			= cub3d.c check_files.c parse.c draw.c
SRCS_DIR		= srcs

LIBS			= lib_sashin.a
LIBS_DIR		= lib

INCLUDES		= includes

all: $(NAME)

$(NAME): $(addprefix $(SRCS_DIR)/, $(SRCS))
	$(CC) $(CFLAGS) $^ $(addprefix $(LIBS_DIR)/, $(LIBS)) -o test_file