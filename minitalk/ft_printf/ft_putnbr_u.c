/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:15:12 by ervsahin          #+#    #+#             */
/*   Updated: 2025/07/22 13:11:59 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static int	ft_uintlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_u(unsigned int n)
{
	char	*str;
	int		len;
	int		i;

	len = ft_uintlen(n);
	i = len;
	str = malloc(len + 1);
	if (str == NULL)
		return (-1);
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	while (i > 0)
	{
		str[--i] = (n % 10) + '0';
		n /= 10;
	}
	len = write(1, str, len);
	free(str);
	if (len < 0)
		return (-1);
	return (len);
}
