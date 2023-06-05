/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:58:13 by lnascari          #+#    #+#             */
/*   Updated: 2022/10/12 14:58:16 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_count(int n)
{
	int			c;
	long int	x;

	c = 1;
	x = 10;
	while (n / x != 0)
	{
		c++;
		x *= 10;
	}
	return (c);
}

static void	ft_make(char *s, int n, int l)
{
	while (n != 0)
	{
		s[l - 1] = n % 10 + 48;
		l--;
		n /= 10;
	}
}

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

static char	*ft_strcpy(const char *src)
{
	unsigned int	i;
	char			*dst;

	dst = malloc(ft_strlen(src) + 1);
	if (!dst)
		return (0);
	i = 0;
	while (src[i] != 0)
	{
		dst[i] = src [i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		sgn;

	if (n == 0)
		return (ft_strcpy("0"));
	if (n == -2147483648)
		return (ft_strcpy("-2147483648"));
	sgn = 0;
	if (n < 0)
	{
		sgn = 1;
		n *= -1;
	}
	s = malloc(ft_count(n) + sgn + 1);
	if (!s)
		return (0);
	s[ft_count(n) + sgn] = 0;
	if (sgn)
		s[0] = '-';
	ft_make(s, n, ft_count(n) + sgn);
	return (s);
}

/* int main()
{
	printf("%s\n", ft_itoa(2147483647));
} */