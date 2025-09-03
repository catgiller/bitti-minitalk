/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 04:28:14 by ervsahin          #+#    #+#             */
/*   Updated: 2025/09/03 05:28:58 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"
#include "minitalk.h"

int	g_ack = 0;

void	signal_handler(int signum, siginfo_t *info, void *data)
{
	(void)info;
	(void)data;
	if (signum == SIGUSR1)
		g_ack = 1;
	if (signum == SIGUSR2)
	{
		ft_printf("%s\n", "The End");
		exit(0);
	}
}

static void	send_char(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_ack = 0;
		if ((c >> bit) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				print_error("Signal Error\n");
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				print_error("Signal Error\n");
		}
		while (!g_ack)
			pause();
		bit--;
	}
}

static void	send_message(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_char(pid, msg[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	main(int ac, char *av[])
{
	long				pid;
	struct sigaction	sa;

	if (ac != 3)
		print_error("Try Again..\n");
	pid = ft_atoi(av[1]);
	if (pid <= 0 || pid > 2147483647 || ft_strlen(av[1]) > 10)
		print_error("Incorrect PID!\n");
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		print_error("Error: sigaction SIGUSR1 failed\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		print_error("Error: sigaction SIGUSR2 failed\n");
	send_message(pid, av[2]);
	while (!g_ack)
	{
		pause();
	}
	return (0);
}
