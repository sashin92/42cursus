# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 15:58:12 by sashin            #+#    #+#              #
#    Updated: 2021/06/19 18:02:10 by sashin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# If you want to add library, add "$(SRC)", "$(SRC_DIR)", dependancy of $(NAME) and clean

NAME			= lib_sashin.a

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra

AR				= ar
ARFLAGS			= -rcs

INCLUDES_DIR	= includes
LIBFT_DIR		= srcs/libft
FT_PRINTF_DIR	= srcs/ft_printf
GNL_DIR			= srcs/get_next_line

LIBFT			= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
				ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
				ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
				ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
				ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

FT_PRINTF		= ft_printf.c printf_check.c printf_tool.c printf_init_flags.c printf_conversion_c.c \
				printf_conversion_s.c printf_conversion_p.c printf_conversion_d.c printf_conversion_u.c printf_conversion_x.c \
				printf_conversion_x_large.c printf_conversion_percent.c

GNL				= get_next_line.c

all: $(NAME)

$(NAME): libft ft_printf gnl

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^
	$(AR) $(ARFLAGS) $(NAME) $@

libft: $(addprefix $(LIBFT_DIR)/, $(LIBFT:.c=.o))
ft_printf: $(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF:.c=.o))
gnl: $(addprefix $(GNL_DIR)/, $(GNL:.c=.o))

clean:
	rm -rf $(addprefix $(LIBFT_DIR)/, $(LIBFT:.c=.o))
	rm -rf $(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF:.c=.o))
	rm -rf $(addprefix $(GNL_DIR)/, $(GNL:.c=.o))

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re libft ft_printf gnl