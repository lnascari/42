/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:08:31 by lnascari          #+#    #+#             */
/*   Updated: 2023/01/18 15:58:58 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(int *a, int *b, int *len_a, int *len_b)
{
	if (*len_b != 0)
	{
		a[*len_a] = b[(*len_b) - 1];
		*len_a += 1;
		*len_b -= 1;
	}
	write(1, "pa\n", 4);
}

void	pb(int *a, int *b, int *len_a, int *len_b)
{
	if (*len_a != 0)
	{
		b[*len_b] = a[(*len_a) - 1];
		*len_b += 1;
		*len_a -= 1;
	}
	write(1, "pb\n", 4);
}
