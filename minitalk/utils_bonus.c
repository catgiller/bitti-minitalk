/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 04:29:21 by ervsahin          #+#    #+#             */
/*   Updated: 2025/09/03 05:29:44 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

long	ft_atoi(const char *nptr)
{
	int		sig;
	long	rst;

	rst = 0;
	sig = 1;
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == 32))
		nptr++;
	if (*nptr == '+')
	{
		sig = 1;
		nptr ++;
	}
	else if (*nptr == '-')
	{
		sig = -1;
		nptr ++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		rst = rst * 10 + (*nptr - '0');
		nptr ++;
	}
	return (rst * sig);
}

unsigned int	ft_strlen(const char *s)
{
	unsigned int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	print_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}
