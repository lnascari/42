/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:55:43 by lnascari          #+#    #+#             */
/*   Updated: 2023/02/03 11:54:57 by lnascari         ###   ########.fr       */
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

int	get_index_a(int n, int *stack, int size)
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

t_operations	count_m_b(int *stack_a, int *stack_b, int size_a, int size_b)
{
	t_operations	op;
	t_operations	min;
	int				i;
	int				index;

	i = size_b;
	while (--i >= 0)
	{
		ft_bzero(&op, sizeof(t_operations));
		index = get_index_a(stack_b[i], stack_a, size_a);
		count_r(index, size_a, &op, 1);
		count_r(i, size_b, &op, 0);
		less_op(&op);
		if (i == size_b - 1 || diff(min, op))
			min = op;
	}
	return (min);
}

void	sort_b(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	t_operations	op;

	op = count_m_b(stack_a, stack_b, *size_a, *size_b);
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
