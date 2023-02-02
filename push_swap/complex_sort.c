/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:55:43 by lnascari          #+#    #+#             */
/*   Updated: 2023/02/02 11:49:39 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(int n, int *stack, int size)
{
	int	i;
	int	index;

	i = -1;
	index = -1;
	while (++i < size)
	{
		if (index == -1)
		{
			if (stack[i] > n)
				index = i;
		}
		else
		{
			if (stack[i] > n && stack[i] < stack[index])
				index = i;
		}
	}
	if (index != -1)
		return (index);
	return (min(stack, size));
}

void	count_r(int index, int size, t_operations *op, int a)
{
	if (index < size / 2)
	{
		if (a)
			op->rra = index + 1;
		else
			op->rrb = index + 1;
	}
	else
	{
		if (a)
			op->ra = size - index - 1;
		else
			op->rb = size - index - 1;
	}
}

t_operations	count_m(int *stack_a, int *stack_b, int size_a, int size_b)
{
	t_operations	*op;
	t_operations	min;
	int				i;
	int				index;

	i = size_b;
	while (--i >= 0)
	{
		op = malloc(sizeof(t_operations));
		index = get_index(stack_b[i], stack_a, size_a);
		count_r(index, size_a, op, 1);
		count_r(i, size_b, op, 0);
		less_op(op);
		if (i == size_b - 1 || diff(min, *op))
			min = *op;
		free(op);
	}
	return (min);
}

void	sort_b(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	t_operations	op;

	op = count_m(stack_a, stack_b, *size_a, *size_b);
	while (op.ra--)
		ra(stack_a, *size_a);
	while (op.rb--)
		rb(stack_b, *size_b);
	while (op.rr--)
		rr(stack_a, stack_b, *size_a, *size_b);
	while (op.rra--)
		rra(stack_a, *size_a);
	while (op.rrb--)
		rrb(stack_b, *size_b);
	while (op.rrr--)
		rrr(stack_a, stack_b, *size_a, *size_b);
	pa(stack_a, stack_b, size_a, size_b);
}
