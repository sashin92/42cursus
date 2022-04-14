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
# usage: "\033['Bright';'Color'm"
RST			= "\033[0m"
BRI			= "\033[1m"
DIM			= "\033[2m"
RED			= "\033[0;31m"
GRN			= "\033[1;32m"
YEL			= "\033[0;33m"
BLU			= "\033[0;34m"
MAG			= "\033[0;35m"
CYN			= "\033[0;36m"
WHT			= "\033[0;37m"
# =========================

NAME		= megaphone

CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98

SRCS		= megaphone.cpp
OBJS		=  $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: re
	./$(NAME)

test: re
	@echo $(GRN)"====================test===================="$(RST)
	./$(NAME) "shhhhh... I think the students are asleep..."
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	./$(NAME)
	./$(NAME) "hello world!"
	./$(NAME) this ' is ' "my" 1st "Sub."
	@echo $(GRN)"============================================"$(RST)
	@make --no-print-directory fclean

.PHONY: all clean fclean re run test
