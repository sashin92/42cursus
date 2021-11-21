# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/19 17:09:40 by sashin            #+#    #+#              #
#    Updated: 2021/11/21 11:19:22 by sashin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

SRCS		= push_swap.c dlist.c parse.c controls.c controls_rev_rotater.c \
				controls_rotater.c controls_swapper_pusher.c small_sort.c \
				a_to_b.c a_to_b_sort.c a_to_b_command.c \
				b_to_a.c b_to_a_sort.c b_to_a_command.c \
				get_pivot.c init.c
SRCS_DIR	= srcs

OBJS		= $(SRCS:.c=.o)

LIBFT		= lib_sashin.a
LIBFT_DIR	= libft

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(addprefix $(SRCS_DIR)/, $(OBJS)) $(addprefix $(LIBFT_DIR)/, $(LIBFT))
	$(CC) $(CFLAGS) $^ -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(addprefix $(SRCS_DIR)/, $(OBJS))

fclean:
	make fclean -C $(LIBFT_DIR)
	rm -rf $(addprefix $(SRCS_DIR)/, $(OBJS))
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
