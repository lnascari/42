/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:29:50 by lnascari          #+#    #+#             */
/*   Updated: 2023/02/07 14:04:59 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	checker_error(int *stack_a, int *stack_b)
{
	free(stack_a);
	free(stack_b);
	write(2, "Error\n", 7);
	exit(0);
}

void	checker_done(int *stack_a, int *stack_b, int ok)
{
	free(stack_a);
	free(stack_b);
	if (ok)
		write(1, "OK\n", 4);
	else
		write(1, "KO\n", 4);
	exit(0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == 0 && s2[i] == 0)
		{
			return (0);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

int	cases(int *stack_a, int *stack_b, t_size *size, char *str)
{
	if (!str)
		return (0);
	if (!ft_strcmp(str, "pa\n"))
		push_a(stack_a, stack_b, &size->size_a, &size->size_b);
	else if (!ft_strcmp(str, "pb\n"))
		push_b(stack_a, stack_b, &size->size_a, &size->size_b);
	else if (!ft_strcmp(str, "sa\n"))
		s(stack_a, size->size_a);
	else if (!ft_strcmp(str, "sb\n"))
		s(stack_b, size->size_b);
	else if (!ft_strcmp(str, "ra\n"))
		r(stack_a, size->size_a);
	else if (!ft_strcmp(str, "rb\n"))
		r(stack_b, size->size_b);
	else if (!ft_strcmp(str, "rr\n"))
		r_rr(stack_a, stack_b, size->size_a, size->size_b);
	else if (!ft_strcmp(str, "rra\n"))
		r_r(stack_a, size->size_a);
	else if (!ft_strcmp(str, "rrb\n"))
		r_r(stack_b, size->size_b);
	else if (!ft_strcmp(str, "rrr\n"))
		r_rrr(stack_a, stack_b, size->size_a, size->size_b);
	else
		checker_error(stack_a, stack_b);
	return (1);
}

void	checker(int *stack_a, int size_a)
{
	t_size	size;
	int		*stack_b;

	stack_b = malloc(sizeof(int) * size_a);
	size.size_a = size_a;
	size.size_b = 0;
	while (cases(stack_a, stack_b, &size, get_next_line(0)))
		;
	checker_done(stack_a, stack_b, check_sort(stack_a, size.size_a));
}
