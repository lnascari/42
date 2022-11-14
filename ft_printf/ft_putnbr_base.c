/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 07:32:21 by lnascari          #+#    #+#             */
/*   Updated: 2022/11/07 14:47:47 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == 43 || base[i] == 45)
			return (0);
		j = 0;
		while (base[j] != 0)
		{
			if (i == j)
			{
				j++;
				continue ;
			}
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

static void	ft_putnbr(long int nbr, char *base, int l, int *n)
{
	if (nbr >= l)
	{
		ft_putnbr(nbr / l, base, l, n);
		ft_putchar(base[nbr % l], n);
	}
	else
	{
		ft_putchar(base[nbr % l], n);
	}
}

void	ft_putnbr_base(long int nbr, char *base, int *n)
{
	int	l;

	l = check_base(base);
	if (l > 1)
	{
		if (nbr < 0)
		{
			nbr *= -1;
			ft_putchar('-', n);
		}
		ft_putnbr(nbr, base, l, n);
	}
}

void	ft_putp(unsigned long int nbr, int *n)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_putp(nbr / 16, n);
		ft_putchar(base[nbr % 16], n);
	}
	else
	{
		ft_putchar(base[nbr % 16], n);
	}
}
