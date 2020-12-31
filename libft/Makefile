CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar
ARFLAGS = crv
NAME = libft.a
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)

%.o: %.c
	gcc $(CFLAGS) -c $<

all: $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:	fclean all