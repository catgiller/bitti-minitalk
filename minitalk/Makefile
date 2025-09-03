
NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

SRCS_SERVER = minitalk/server.c minitalk/utils.c minitalk/ft_printf/libftprintf.a
SRCS_CLIENT = minitalk/client.c minitalk/utils.c minitalk/ft_printf/libftprintf.a
SRCS_SERVER_BONUS = minitalk/server_bonus.c minitalk/utils_bonus.c minitalk/ft_printf/libftprintf.a
SRCS_CLIENT_BONUS = minitalk/client_bonus.c minitalk/utils_bonus.c minitalk/ft_printf/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: ft_printf $(NAME_SERVER) $(NAME_CLIENT)

bonus: ft_printf $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

ft_printf:
	$(MAKE) -C minitalk/ft_printf

$(NAME_SERVER): $(SRCS_SERVER)
	$(CC) $(CFLAGS) minitalk/server.c minitalk/utils.c minitalk/ft_printf/libftprintf.a -o minitalk/server

$(NAME_CLIENT): $(SRCS_CLIENT)
	$(CC) $(CFLAGS) minitalk/client.c minitalk/utils.c minitalk/ft_printf/libftprintf.a -o minitalk/client

$(NAME_SERVER_BONUS): $(SRCS_SERVER_BONUS)
	$(CC) $(CFLAGS) minitalk/server_bonus.c minitalk/utils_bonus.c minitalk/ft_printf/libftprintf.a -o minitalk/server_bonus

$(NAME_CLIENT_BONUS): $(SRCS_CLIENT_BONUS)
	$(CC) $(CFLAGS) minitalk/client_bonus.c minitalk/utils_bonus.c minitalk/ft_printf/libftprintf.a -o minitalk/client_bonus

clean:
	$(MAKE) -C minitalk/ft_printf clean
	rm -f minitalk/*.o minitalk/*.o minitalk/*.gch

fclean: clean
	$(MAKE) -C minitalk/ft_printf fclean
	rm -f minitalk/$(NAME_SERVER) minitalk/$(NAME_CLIENT) minitalk/$(NAME_SERVER_BONUS) minitalk/$(NAME_CLIENT_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re ft_printf
