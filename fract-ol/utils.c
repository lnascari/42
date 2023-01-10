/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:30:57 by lnascari          #+#    #+#             */
/*   Updated: 2023/01/10 11:35:13 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*ft_tolower(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] > 64 && s[i] < 91)
			s[i] += 32;
	}
	return (s);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] == 0)
			return (-1);
		if (s2[i] == 0)
			return (1);
		if (s1[i] > s2[i])
		{
			return (1);
		}
		else if (s1[i] < s2[i])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

int	getpower(int n)
{
	int	x;

	x = 1;
	while (n >= 1)
	{
		n /= 10;
		x *= 10;
	}
	return (x / 10);
}

double	num(char *s)
{
	double	n;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (s[i] == '+')
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (s[i] != '0' || (s[i + 1] != 0 && s[i + 1] != '.'))
		return (-1);
	if (s[++i] == 0)
		return (0);
	s[i] = '1';
	n = ft_atoi(&s[i]);
	if (!n)
		return (0);
	return ((n / getpower((int) n) - 1) * sign);
}
