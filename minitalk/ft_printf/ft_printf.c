/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:09:20 by ervsahin          #+#    #+#             */
/*   Updated: 2025/07/22 14:06:21 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static int	is_valid_format(char c)
{
	return (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'p' || c == 'x' || c == 'X' || c == '%');
}

static int	find_format(char f, va_list args)
{
	if (f == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (f == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (f == 'd' || f == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (f == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	if (f == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (f == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	if (f == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	if (f == '%')
		return (ft_putchar('%'));
	return (-1);
}

static int	ft_print_format(const char *format, va_list args, int *cnt)
{
	int	tmp;

	while (*format)
	{
		if (*format == '%' && is_valid_format(*(format + 1)))
		{
			tmp = find_format(*(++format), args);
			if (tmp < 0)
				return (va_end(args), -1);
			*cnt += tmp;
		}
		else if (*format == '%' && !is_valid_format(*(format + 1)))
			return (va_end(args), -1);
		else
		{
			if (write(1, format, 1) < 0)
				return (va_end(args), -1);
			(*cnt)++;
		}
		format++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		cnt;
	int		tmp;

	if (format == 0)
		return (-1);
	cnt = 0;
	va_start(args, format);
	tmp = ft_print_format(format, args, &cnt);
	if (tmp < 0)
		return (-1);
	va_end(args);
	return (cnt);
}
