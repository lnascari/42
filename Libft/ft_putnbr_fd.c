/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:37:38 by lnascari          #+#    #+#             */
/*   Updated: 2022/10/12 17:37:40 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

static int	nb_p(int n, int fd);
static int	count_d(int n, int d);
static int	nb_write(int v[], int i, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	int	i;
	int	d;
	int	v[10];

	n = nb_p(n, fd);
	d = count_d(n, 0);
	i = 0;
	while (i < d)
	{
		v[i] = n % 10;
		n /= 10;
		i++;
	}
	nb_write(v, d - 1, fd);
}

static int	nb_p(int nb, int fd)
{
	if (nb == 0)
	{
		write(fd, "0", 1);
		return (0);
	}
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (0);
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
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

static int	nb_write(int v[], int i, int fd)
{
	char	w;

	if (i >= 0)
	{
		w = v[i] + 48;
		write(fd, &w, 1);
		nb_write(v, i - 1, fd);
	}
	return (0);
}

/* int	main()
{
	ft_putnbr_fd(2147483647, 1);
} */