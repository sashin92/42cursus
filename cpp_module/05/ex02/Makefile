# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 10:04:50 by sashin            #+#    #+#              #
#    Updated: 2022/04/27 20:38:01 by sashin           ###   ########.fr        #
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

# debug in linux(memcheck): valgrind --leak-check=full --log-file=memcheck.txt -v --error-limit=no ./$(NAME)
NAME		= a.out

CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98

SRCS		= main.cpp \
				Bureaucrat.cpp \
				Form.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp

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

# usage: make -i test
test: re
	@echo $(GRN)"====================test===================="$(RST)
	./$(NAME)
	@echo $(GRN)"============================================"$(RST)
	@make --no-print-directory fclean

.PHONY: all clean fclean re run test
