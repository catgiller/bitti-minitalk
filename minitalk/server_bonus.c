/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 04:28:01 by ervsahin          #+#    #+#             */
/*   Updated: 2025/09/03 05:29:25 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"
#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *data)
{
	static int				bit_cnt = 0;
	static unsigned char	char_cnt = 0;

	(void)data;
	if (signum == SIGUSR2)
		char_cnt |= 1 << (7 - bit_cnt);
	bit_cnt++;
	if (bit_cnt == 8)
	{
		if (char_cnt == '\0')
		{
			write(1, "\n", 1);
			if (kill(info->si_pid, SIGUSR2) == -1)
				print_error("Signal Error\n");
			bit_cnt = 0;
			char_cnt = 0;
			return ;
		}
		else
			write(1, &char_cnt, 1);
		bit_cnt = 0;
		char_cnt = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		print_error("Signal Error\n");
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		print_error("Error: sigaction SIGUSR1 failed\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		print_error("Error: sigaction SIGUSR2 failed\n");
	while (1)
		pause();
}
