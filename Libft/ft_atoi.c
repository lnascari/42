/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:51:37 by lnascari          #+#    #+#             */
/*   Updated: 2023/06/08 15:53:59 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	n;
	int		sgn;

	while ((*str > 8 && *str < 14) || *str == ' ')
		str++;
	sgn = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sgn = -1;
	}
	n = 0;
	while (*str >= '0' && *str <= '9')
		n = n * 10 + *str++ - 48;
	return ((int)(n * sgn));
}
