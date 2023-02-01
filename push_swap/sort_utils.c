/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:41:56 by lnascari          #+#    #+#             */
/*   Updated: 2023/02/01 15:06:01 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(int *stack, int size)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (++i < size)
	{
		if (stack[i] < stack[min])
			min = i;
	}
	return (min);
}

int	diff(t_operations min, t_operations op)
{
	int	n1;
	int	n2;

	n1 = min.ra + min.rb + min.rr + min.rra + min.rrb + min.rrr;
	n2 = op.ra + op.rb + op.rr + op.rra + op.rrb + op.rrr;
	return (n2 < n1);
}
