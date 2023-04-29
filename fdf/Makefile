NAME = fdf

LIBFT = libft/libft.a
PRINTF = ft_printf/ft_printf.a
GNL = gnl/gnl.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
LIBS = -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit


SRCS = \
	fdf.c \
	parse.c \
	main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) all -C libft
	$(MAKE) all -C ft_printf
	$(MAKE) all -C gnl
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(LIBFT) $(PRINTF) $(GNL) -o $(NAME)

%.o: %.c fdf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) clean -C libft
	$(MAKE) clean -C ft_printf
	$(MAKE) clean -C gnl


fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C ft_printf
	$(MAKE) fclean -C gnl

re: fclean all

.PHONY: all clean fclean re
