/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:07:15 by gpaoline          #+#    #+#             */
/*   Updated: 2022/10/06 16:07:16 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_numlen(int n)
{
	int	tmp;
	int	len;

	len = 0;
	tmp = n;
	if (tmp == -2147483648)
	{
		len += 2;
		tmp = 147483648;
	}
	else if (tmp < 0)
	{
		tmp *= -1;
		len ++;
	}
	else if (tmp == 0)
		len ++;
	while (tmp > 0)
	{
		tmp = tmp / 10;
		len ++;
	}
	return (len);
}

static char	*ft_array(char *num, int nb, int i)
{
	if (nb < 0)
	{
		num[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		num[i] = (nb % 10) + 48;
		nb = nb / 10;
		i --;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		nb;
	int		i;

	nb = n;
	i = ft_numlen(nb);
	num = (char *)malloc(i + 1 * sizeof(char));
	if (num == 0)
		return (0);
	num[i--] = '\0';
	if (nb == 0)
	{
		num[i] = '0';
		return (num);
	}
	else if (nb == -2147483648)
	{
		num[0] = '-';
		num[1] = '2';
		nb = 147483648;
	}
	num = ft_array(num, nb, i);
	return (num);
}

/* int main()
{
	int n = -3452;
	printf("%s\n", ft_itoa(n));
} */