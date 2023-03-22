NAME = libftprintf.a

LIBFT = libft.a

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror

SRCS = \
		ft_printf.c\
		ft_printf_text.c\
		ft_printf_num.c

OBJS = \
		ft_printf.o\
		ft_printf_text.o\
		ft_printf_num.o

all: $(NAME)

$(NAME):
	$(CC) $(CC_FLAGS) -c $(SRCS)
	$(MAKE) all -C libft
	cp libft/$(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJS) $(NAME)

clean:
	rm -rf $(OBJS)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) clean -C libft

re: fclean all
