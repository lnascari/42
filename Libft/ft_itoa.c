/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:56:11 by lnascari          #+#    #+#             */
/*   Updated: 2023/06/07 10:57:44 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_tostr(int n, int sgn)
{
	char	*str;
	int		tmp;
	int		i;

	tmp = n;
	i = 0;
	while (tmp >= 1)
	{
		i++;
		tmp /= 10;
	}
	str = ft_calloc(i + sgn + 1, sizeof(char));
	if (!str)
		return (0);
	while (n >= 1)
	{
		str[--i + sgn] = n % 10 + 48;
		n /= 10;
	}
	if (sgn)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int	sgn;

	if (!n)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sgn = 1;
	if (n < 0)
		sgn = -1;
	return (ft_tostr(n * sgn, sgn == -1));
}
