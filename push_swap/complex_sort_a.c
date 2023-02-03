/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:55:43 by lnascari          #+#    #+#             */
/*   Updated: 2023/02/03 11:55:05 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int *stack, int size)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (++i < size)
	{
		if (stack[i] > stack[max])
			max = i;
	}
	return (max);
}

int	get_index_b(int n, int *stack, int size)
{
	int	i;
	int	index;

	i = -1;
	index = -1;
	while (++i < size)
	{
		if (index == -1)
		{
			if (stack[i] < n)
				index = i;
		}
		else
		{
			if (stack[i] < n && stack[i] > stack[index])
				index = i;
		}
	}
	if (index != -1)
		return (index);
	return (max(stack, size));
}

t_operations	count_m_a(int *stack_a, int *stack_b, int size_a, int size_b)
{
	t_operations	op;
	t_operations	min;
	int				i;
	int				index;

	i = size_a;
	while (--i >= 0)
	{
		ft_bzero(&op, sizeof(t_operations));
		index = get_index_b(stack_a[i], stack_b, size_b);
		count_r(index, size_b, &op, 0);
		count_r(i, size_a, &op, 1);
		less_op(&op);
		if (i == size_a - 1 || diff(min, op))
			min = op;
	}
	return (min);
}

void	sort_a(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	t_operations	op;

	op = count_m_a(stack_a, stack_b, *size_a, *size_b);
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
	pb(stack_a, stack_b, size_a, size_b);
}
