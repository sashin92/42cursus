# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 11:25:19 by sashin            #+#    #+#              #
#    Updated: 2022/01/06 11:25:19 by sashin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==========Color==========
# usage: "\x1B['Bright';'Color'm"
RST			= "\x1B[0m"
BRI			= "\x1B[1m"
DIM			= "\x1B[2m"
RED			= "\x1B[0;31m"
GRN			= "\x1B[1;32m"
YEL			= "\x1B[0;33m"
BLU			= "\x1B[0;34m"
MAG			= "\x1B[0;35m"
CYN			= "\x1B[0;36m"
WHT			= "\x1B[0;37m"
# =========================

NAME		= tests

CXX			= clang++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98

SRCS		= tests.cpp \
				Account.cpp
OBJS		=  $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: all
	./$(NAME)

test: all
	./$(NAME)
	@make fclean

.PHONY: all clean fclean re run test