/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:00:03 by lnascari          #+#    #+#             */
/*   Updated: 2022/10/05 13:00:05 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static void	str_spc(const char *str, int *i);
static int	str_sgn(const char *str, int *i);
static int	mk_n(int *arr, int d);

int	ft_atoi(const char *str)
{
	int	i;
	int	sgn;
	int	d;
	int	arr[10];

	i = 0;
	d = 0;
	str_spc(str, &i);
	sgn = str_sgn(str, &i);
	while (str[i] != 0 && (str[i] > 47 && str[i] < 58))
	{
		arr[d] = str[i] - 48;
		d++;
		i++;
	}
	if (sgn)
	{
		return (mk_n(arr, d) * -1);
	}
	return (mk_n(arr, d));
}

static void	str_spc(const char *str, int *i)
{
	while (str[*i] != 0)
	{
		if ((str[*i] > 8 && str[*i] < 14) || str[*i] == 32)
		{
			*i += 1;
		}
		else
		{
			break ;
		}
	}
}

static int	str_sgn(const char *str, int *i)
{
	int	sgn;

	sgn = 0;
	if (str[*i] == 43 || str[*i] == 45)
	{
		if (str[*i] == 45)
		{
			sgn++;
		}
		*i += 1;
	}
	return (sgn);
}

static int	mk_n(int *arr, int d)
{
	int	i;
	int	p;
	int	n;

	i = d;
	p = 1;
	n = 0;
	while (i > 0)
	{
		n += arr[i - 1] * p;
		p *= 10;
		i--;
	}
	return (n);
}

/* int main(){
	printf("%d\n", ft_atoi("    \t +214748364cca1"));
} */