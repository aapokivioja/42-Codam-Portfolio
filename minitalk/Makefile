NAME = client
SERVNAME = server

LIBFT = libft/libft.a
PRINTF = ft_printf/ft_printf.a

HEADER = minitalk.h

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror

SRCSS = server.c
OBJSS = $(SRCSS:.c=.o)

SRCSC = client.c
OBJSC = $(SRCSC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME) $(SERVNAME)

$(NAME): $(OBJSC) $(LIBFT) $(PRINTF) $(HEADER)
	$(CC) $(CC_FLAGS) $(OBJSC) $(LIBFT) $(PRINTF) -o $(NAME)

$(SERVNAME): $(OBJSS) $(LIBFT) $(PRINTF) $(HEADER)
	$(CC) $(CC_FLAGS) $(OBJSS) $(LIBFT) $(PRINTF) -o $(SERVNAME)

%.o: %.c $(HEADER)
	$(CC) $(CC_FLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) all -C libft

$(PRINTF):
	$(MAKE) all -C ft_printf

clean:
	rm -rf $(OBJSS) $(OBJSC)
	$(MAKE) clean -C libft
	$(MAKE) clean -C ft_printf

fclean: clean
	rm -f $(NAME) $(SERVNAME)
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C ft_printf

re: fclean all
