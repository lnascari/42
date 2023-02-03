/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:41:56 by lnascari          #+#    #+#             */
/*   Updated: 2023/02/03 11:48:43 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}

void	ft_bzero(void *s, int n)
{
	char	*str;
	int		i;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	final_sort(int *stack, int size)
{
	int	index;
	int	n;

	index = min(stack, size);
	if (index < size / 2)
	{
		n = index + 1;
		while (n--)
			rra(stack, size);
	}
	else
	{
		n = size - index - 1;
		while (n--)
			ra(stack, size);
	}
}
