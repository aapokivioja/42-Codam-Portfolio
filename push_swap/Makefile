NAME = push_swap

LIBFT = libft/libft.a
PRINTF = ft_printf/ft_printf.a

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror -fsanitize=address

SRCS = \
		dllistfunctions.c\
		alg.c\
		operations.c\
		push_swap.c\
		main.c\
		error_and_checks.c

OBJS = \
		dllistfunctions.o\
		alg.o\
		operations.o\
		push_swap.o\
		main.o\
		error_and_checks.o

all: $(NAME)

$(NAME):
	$(MAKE) all -C libft
	$(MAKE) all -C ft_printf
	$(CC) $(CC_FLAGS) $(SRCS) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	rm -rf $(OBJS)
	$(MAKE) clean -C libft
	$(MAKE) clean -C ft_printf

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C ft_printf

re: fclean all
