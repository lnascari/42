/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:08:31 by lnascari          #+#    #+#             */
/*   Updated: 2023/02/07 12:31:37 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(int *a, int *b, int *len_a, int *len_b)
{
	if (*len_b != 0)
	{
		a[*len_a] = b[(*len_b) - 1];
		*len_a += 1;
		*len_b -= 1;
	}
}

void	push_b(int *a, int *b, int *len_a, int *len_b)
{
	if (*len_a != 0)
	{
		b[*len_b] = a[(*len_a) - 1];
		*len_b += 1;
		*len_a -= 1;
	}
}

void	pa(int *a, int *b, int *len_a, int *len_b)
{
	push_a(a, b, len_a, len_b);
	write(1, "pa\n", 3);
}

void	pb(int *a, int *b, int *len_a, int *len_b)
{
	push_b(a, b, len_a, len_b);
	write(1, "pb\n", 3);
}
