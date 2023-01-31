/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:19:26 by lnascari          #+#    #+#             */
/*   Updated: 2023/01/31 14:03:56 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(int *stack, int *size)
{
	int	i;

	i = 0;
	while (++i < *size)
	{
		if (stack[i] > stack[i - 1])
			return (0);
	}
	return (1);
}

void	sort_a(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	swap_a;
	int	swap_b;

	while (stack_a[*size_a - 1] > stack_a[0])
		ra(stack_a, *size_a);
	swap_a = stack_a[*size_a - 1] > stack_a[*size_a - 2];
	swap_b = *size_b > 1 && stack_b[*size_b - 1] < stack_b[*size_b - 2];
	if (swap_a && !swap_b)
		sa(stack_a, *size_a);
	else if (!swap_a && swap_b)
		sb(stack_b, *size_b);
	else if (swap_a && swap_b)
		ss(stack_a, stack_b, *size_a, *size_b);
	if (*size_b == 0 && check_sort(stack_a, size_a))
		exit(0);
	pb(stack_a, stack_b, size_a, size_b);
}

void	sort_b(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	swap_a;
	int	swap_b;

	while (stack_b[*size_b - 1] < stack_b[0])
		rb(stack_b, *size_b);
	swap_a = stack_a[*size_a - 1] > stack_a[*size_a - 2];
	swap_b = *size_b > 1 && stack_b[*size_b - 1] < stack_b[*size_b - 2];
	if (swap_a && !swap_b)
		sa(stack_a, *size_a);
	else if (!swap_a && swap_b)
		sb(stack_b, *size_b);
	else if (swap_a && swap_b)
		ss(stack_a, stack_b, *size_a, *size_b);
	pa(stack_a, stack_b, size_a, size_b);
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
	while (size_a > 3)
		sort_a(stack_a, stack_b, &size_a, &size_b);
	sort_3(stack_a, &size_a);
	while (size_b != 0)
		sort_b(stack_a, stack_b, &size_a, &size_b);
}
