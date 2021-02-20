NAME = libftprintf.a

LIBFT = libft.a
LIBFTDIR = ./libft


CC = gcc
CFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS = rcs

SRCS = ft_printf.c printf_check.c printf_tool.c printf_init_flags.c \
		printf_conversion_c.c printf_conversion_s.c printf_conversion_p.c \
		printf_conversion_d.c printf_conversion_u.c printf_conversion_x.c \
		printf_conversion_x_large.c printf_conversion_percent.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	make bonus -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	make clean -C $(LIBFTDIR)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBFTDIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re