/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:58:46 by ervsahin          #+#    #+#             */
/*   Updated: 2025/07/22 13:15:29 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static int	ft_counthex(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (1);
	while (ptr > 0)
	{
		ptr /= 16;
		count++;
	}
	return (count);
}

static int	ft_printhex(unsigned long ptr)
{
	char	*str;
	int		len;
	int		i;

	len = ft_counthex(ptr);
	str = (char *)malloc(len + 1);
	if (!str)
		return (-1);
	str[0] = '0';
	str[len] = '\0';
	i = len - 1;
	while (ptr > 0)
	{
		if (ptr % 16 < 10)
			str[i] = (ptr % 16) + '0';
		else
			str[i] = (ptr % 16) - 10 + 'a';
		ptr /= 16;
		i--;
	}
	len = write(1, str, len);
	free(str);
	if (len < 0)
		return (-1);
	return (len);
}

int	ft_putptr(void *ptr)
{
	int				count;
	unsigned long	p;
	int				check;

	if (!ptr)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	if (count < 0)
		return (-1);
	p = (unsigned long)ptr;
	check = ft_printhex(p);
	if (check < 0)
		return (-1);
	count += check;
	return (count);
}
