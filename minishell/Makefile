# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 16:21:09 by sashin            #+#    #+#              #
#    Updated: 2021/12/23 15:25:05 by sashin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= minishell

#########  mac  #########
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -g
# CDEBUG				= -fsanitize=address -g
READLINE			= -lreadline -L/Users/$(USER)/.brew/opt/readline/lib
READLINE_INC_PATH	= /Users/$(USER)/.brew/opt/readline/include
# READLINE	= -lreadline -L/usr/local/opt/readline/lib
# READLINE_INC_PATH	= /usr/local/opt/readline/include
#########################

######### linux #########
# CC				= clang
# # CFLAGS			= -Wall -Werror -Wextra
# # CDEBUG			= -fsanitize=address -g
# READLINE			= -lreadline -L/lib/x86_64-linux-gnu
# READLINE_INC_PATH	= /usr/include
#########################


INCLUDES_DIR		= includes
SRCS_DIR			= srcs
SRCS				= main.c \
						logo.c \
						parsing/parse.c \
						parsing/parse_cmds.c \
						parsing/parse_cmds2.c \
						parsing/parse_spc.c \
						parsing/parse_quote.c \
						parsing/parse_dquote.c \
						lib/ft_atoi.c \
						lib/ft_putchar_fd.c \
						lib/ft_putstr_fd.c \
						lib/ft_strdup.c \
						lib/ft_strjoin.c \
						lib/ft_strncmp.c \
						lib/ft_substr.c \
						lib/ft_strnew.c \
						lib/ft_strnjoin.c \
						lib/ft_isspace.c \
						lib/ft_isalpha.c \
						lib/ft_strlen.c \
						lib/ft_memset.c \
						lib/ft_strcmp.c \
						lib/ft_isdigit.c \
						lib/ft_split.c \
						lib/ft_dfree.c \
						lib/ft_strrchr.c \
						lib/ft_itoa.c \
						utils/check.c \
						utils/lst_env.c \
						utils/lst_env_combine.c \
						utils/lst_env_control.c \
						utils/lst_env_divide.c \
						utils/lst_env_renew.c \
						utils/lst_args.c \
						utils/lst_cmds.c \
						utils/error.c \
						utils/termios.c \
						commands/bin_cmds.c \
						commands/builtin_cd.c \
						commands/builtin_echo.c \
						commands/builtin_env.c \
						commands/builtin_exit.c \
						commands/builtin_pwd.c \
						commands/builtin_unset.c \
						commands/builtin_export.c \
						exec/exec.c \
						exec/exec_child.c \
						exec/redirection.c \
						exec/heredoc.c \
						utils/signal.c

OBJS				= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(addprefix $(SRCS_DIR)/, $(OBJS))
	$(CC) $(CFLAGS) $(CDEBUG) $(READLINE) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(CDEBUG) -I $(INCLUDES_DIR) -I $(READLINE_INC_PATH) -c $^ -o $@

clean:
	rm -rf $(addprefix $(SRCS_DIR)/, $(OBJS))

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
