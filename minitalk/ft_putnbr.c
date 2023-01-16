/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:53:45 by lnascari          #+#    #+#             */
/*   Updated: 2023/01/16 15:21:43 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	nb_p(int n);
static int	count_d(int n, int d);
static int	nb_write(int v[], int i);

void	ft_putnbr(int nb)
{
	int	i;
	int	d;
	int	v[10];

	nb = nb_p(nb);
	d = count_d(nb, 0);
	i = 0;
	while (i < d)
	{
		v[i] = nb % 10;
		nb /= 10;
		i++;
	}
	nb_write(v, d - 1);
}

static int	nb_p(int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return (0);
	}
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (0);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		return (nb * -1);
	}
	return (nb);
}

static int	count_d(int n, int d)
{
	if (n > 0)
	{
		return (count_d(n / 10, d + 1));
	}
	return (d);
}

static int	nb_write(int v[], int i)
{
	char	w;

	if (i >= 0)
	{
		w = v[i] + 48;
		write(1, &w, 1);
		nb_write(v, i - 1);
	}
	return (0);
}
