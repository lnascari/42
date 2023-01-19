/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:47:26 by lnascari          #+#    #+#             */
/*   Updated: 2023/01/19 12:14:43 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_r(int *arr, int len)
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
	r_r(a, len);
}

void	rrb(int *b, int len)
{
	r_r(b, len);
	write(1, "rrb\n", 5);
}

void	rrr(int *a, int *b, int len_a, int len_b)
{
	r_r(a, len_a);
	r_r(b, len_b);
	write(1, "rrr\n", 5);
}
