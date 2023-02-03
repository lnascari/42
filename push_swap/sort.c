/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:19:26 by lnascari          #+#    #+#             */
/*   Updated: 2023/02/03 12:29:45 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	done(int *stack_a, int *stack_b)
{
	free(stack_a);
	free(stack_b);
	exit(0);
}

int	check_sort(int *stack, int size)
{
	int	i;

	i = 0;
	while (++i < size)
	{
		if (stack[i] > stack[i - 1])
			return (0);
	}
	return (1);
}

void	sort_3(int *stack, int *size)
{
	if (*size > 1)
	{
		if (*size == 2)
		{
			if (stack[1] > stack[0])
				sa(stack, *size);
		}
		else
		{
			if ((stack[0] < stack[1]) && (stack[0] > stack[2]))
			{
				sa(stack, *size);
				ra(stack, *size);
			}
			else
			{
				while (stack[*size - 1] > stack[0])
					ra(stack, *size);
				if (stack[*size - 1] > stack[*size - 2])
					sa(stack, *size);
			}
		}
	}
}

void	sort(int *stack_a, int size_a)
{
	int	*stack_b;
	int	size_b;

	stack_b = malloc(sizeof(int) * size_a);
	size_b = 0;
	if (check_sort(stack_a, size_a))
		done(stack_a, stack_b);
	if (size_a == 4)
		pb(stack_a, stack_b, &size_a, &size_b);
	else if (size_a > 3)
	{
		pb(stack_a, stack_b, &size_a, &size_b);
		pb(stack_a, stack_b, &size_a, &size_b);
	}
	while (size_a > 3)
		sort_a(stack_a, stack_b, &size_a, &size_b);
	sort_3(stack_a, &size_a);
	while (size_b != 0)
		sort_b(stack_a, stack_b, &size_a, &size_b);
	final_sort(stack_a, size_a);
	done(stack_a, stack_b);
}
