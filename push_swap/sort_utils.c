/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:41:56 by lnascari          #+#    #+#             */
/*   Updated: 2023/02/01 23:20:37 by lnascari         ###   ########.fr       */
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

void	less_op(t_operations *op)
{
	int	min_r;
	int	min_rr;

	if (op->ra < op->rb)
		min_r = op->ra;
	else
		min_r = op->rb;
	if (op->rra < op->rrb)
		min_rr = op->rra;
	else
		min_rr = op->rrb;
	op->ra -= min_r;
	op->rb -= min_r;
	op->rr = min_r;
	op->rra -= min_rr;
	op->rrb -= min_rr;
	op->rrr = min_rr;
	op->pa = 1;
}

void	final_sort(int *stack, int size)
{
	int	index;
	int	n;

	index = min(stack, size);
	if (index > size / 2)
	{
		n = size - index;
		while (n--)
			ra(stack, size);
	}
	else
	{
		n = index;
		while (n--)
			rra(stack, size);
	}
}
