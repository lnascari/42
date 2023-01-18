/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:47:26 by lnascari          #+#    #+#             */
/*   Updated: 2023/01/18 15:54:51 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rr(int *arr, int len)
{
	int	*tmp;
	int	i;

	if (len > 1)
	{
		tmp = malloc(len * sizeof(int));
		i = -1;
		while (++i < len)
			tmp[i] = arr[i];
		arr[len -1] = tmp[0];
		i = 0;
		while (++i < len)
			arr[i - 1] = tmp[i];
		free(tmp);
	}
}

void	rra(int *a, int len)
{
	write(1, "rra\n", 5);
	rr(a, len);
}

void	rrb(int *b, int len)
{
	rr(b, len);
	write(1, "rrb\n", 5);
}

void	rrr(int *a, int *b, int len_a, int len_b)
{
	rr(a, len_a);
	rr(b, len_b);
	write(1, "rrr\n", 5);
}
