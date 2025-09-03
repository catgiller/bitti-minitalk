NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

SRCS_SERVER = server.c utils.c
SRCS_CLIENT = client.c utils.c
SRCS_SERVER_BONUS = server_bonus.c utils_bonus.c
SRCS_CLIENT_BONUS = client_bonus.c utils_bonus.c
LIBFT_PRINTF = ft_printf/libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
all: ft_printf $(NAME_SERVER) $(NAME_CLIENT)
bonus:  $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(LIBFT_PRINTF):
	$(MAKE) -C ft_printf
$(NAME_SERVER): $(SRCS_SERVER) $(LIBFT_PRINTF)
	$(CC) $(CFLAGS) $(SRCS_SERVER) $(LIBFT_PRINTF) -o $(NAME_SERVER)
$(NAME_CLIENT): $(SRCS_CLIENT) $(LIBFT_PRINTF)
	$(CC) $(CFLAGS) $(SRCS_CLIENT) $(LIBFT_PRINTF) -o $(NAME_CLIENT)
$(NAME_SERVER_BONUS): $(SRCS_SERVER_BONUS) $(LIBFT_PRINTF)
	$(CC) $(CFLAGS) $(SRCS_SERVER_BONUS) $(LIBFT_PRINTF) -o $(NAME_SERVER_BONUS)
$(NAME_CLIENT_BONUS): $(SRCS_CLIENT_BONUS) $(LIBFT_PRINTF)
	$(CC) $(CFLAGS) $(SRCS_CLIENT_BONUS) $(LIBFT_PRINTF) -o $(NAME_CLIENT_BONUS)
clean:
	$(MAKE) -C ft_printf clean
	rm -f *.o 
fclean: clean
	$(MAKE) -C ft_printf fclean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
re: fclean all
.PHONY: all bonus clean fclean re ft_printf
