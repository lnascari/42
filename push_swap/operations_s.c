/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:56:15 by lnascari          #+#    #+#             */
/*   Updated: 2023/01/18 15:55:15 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	s(int *arr, int len)
{
	int	x;

	if (len > 1)
	{
		x = arr[len - 1];
		arr[len - 1] = arr[len - 2];
		arr[len - 2] = x;
	}
}

void	sa(int *a, int len)
{
	write(1, "sa\n", 4);
	s(a, len);
}

void	sb(int *b, int len)
{
	s(b, len);
	write(1, "sb\n", 4);
}

void	ss(int *a, int *b, int len_a, int len_b)
{
	s(a, len_a);
	s(b, len_b);
	write(1, "ss\n", 4);
}
