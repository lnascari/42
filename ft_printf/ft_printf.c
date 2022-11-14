/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:15:29 by lnascari          #+#    #+#             */
/*   Updated: 2022/11/07 14:28:34 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "lib.h"

void	ft_putchar(char c, int *n)
{
	write(1, &c, 1);
	*n += 1;
}

void	ft_putstr(char *s, int *n)
{
	int		i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			ft_putchar(s[i], n);
			i++;
		}
	}
	else
		ft_putstr("(null)", n);
}

void	ft_putpointer(unsigned long int p, int *n)
{
	if (p)
	{
		ft_putstr("0x", n);
		ft_putp(p, n);
	}
	else
	{
		ft_putstr("(nil)", n);
	}
}

static	void	ft_cases(const char *s, va_list	p, int *n)
{
	if (*s == 'c')
		ft_putchar(va_arg(p, int), n);
	else if (*s == 's')
		ft_putstr(va_arg(p, char *), n);
	else if (*s == 'p')
		ft_putpointer(va_arg(p, unsigned long int), n);
	else if (*s == 'd' || *s == 'i')
		ft_putnbr_base(va_arg(p, int), "0123456789", n);
	else if (*s == 'u')
		ft_putnbr_base(va_arg(p, unsigned int), "0123456789", n);
	else if (*s == 'x')
		ft_putnbr_base(va_arg(p, unsigned int), "0123456789abcdef", n);
	else if (*s == 'X')
		ft_putnbr_base(va_arg(p, unsigned int), "0123456789ABCDEF", n);
	else if (*s == '%')
		ft_putchar('%', n);
	else
	{
		ft_putchar('%', n);
		ft_putchar(*s, n);
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	p;
	int		n;

	n = 0;
	va_start(p, s);
	while (*s)
	{
		if (*s != '%')
		{
			ft_putchar(*s, &n);
			s++;
		}
		else
		{
			if (!*(s + 1))
			{
				va_end(p);
				return (-1);
			}
			ft_cases(s + 1, p, &n);
			s += 2;
		}	
	}
	va_end(p);
	return (n);
}
