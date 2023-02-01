/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:55:43 by lnascari          #+#    #+#             */
/*   Updated: 2023/02/01 15:06:56 by lnascari         ###   ########.fr       */
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

void	count_r(int index, int *stack, int size, t_operations *op)
{

}

t_operations	count_m(int *stack_a, int *stack_b, int size_a, int size_b)
{
	t_operations	*op;
	t_operations	min;
	int				i;
	int				r;
	int				index;

	i = size_b;
	while (--i >= 0)
	{
		op = malloc(sizeof(t_operations));
		index = get_index(stack_b[i], stack_a, size_a);
		count_r(index, stack_a, size_a, op);
		count_r(i * -1, stack_b, size_b, op);
		less_op(op);
		if (i == size_b - 1 || diff(min, op))
			min = *op;
		free(op);
	}
	return (min);
}

void	sort_b(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	i;
	int	m;

	i = *size_b;
}
