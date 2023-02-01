/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:31:26 by lnascari          #+#    #+#             */
/*   Updated: 2023/02/01 12:09:13 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r(int *arr, int len)
{
	int	*tmp;
	int	i;

	if (len > 1)
	{
		tmp = malloc(len * sizeof(int));
		i = -1;
		while (++i < len)
			tmp[i] = arr[i];
		arr[0] = tmp[len -1];
		i = 0;
		while (++i < len)
			arr[i] = tmp[i - 1];
		free(tmp);
	}
}

void	ra(int *a, int len)
{
	write(1, "ra\n", 3);
	r(a, len);
}

void	rb(int *b, int len)
{
	r(b, len);
	write(1, "rb\n", 3);
}

void	rr(int *a, int *b, int len_a, int len_b)
{
	r(a, len_a);
	r(b, len_b);
	write(1, "rr\n", 3);
}
