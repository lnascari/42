/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:01:08 by lnascari          #+#    #+#             */
/*   Updated: 2023/02/01 15:07:45 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

void	sa(int *a, int len);
void	sb(int *b, int len);
void	ss(int *a, int *b, int len_a, int len_b);
void	pa(int *a, int *b, int *len_a, int *len_b);
void	pb(int *a, int *b, int *len_a, int *len_b);
void	ra(int *a, int len);
void	rb(int *b, int len);
void	rr(int *a, int *b, int len_a, int len_b);
void	rra(int *a, int len);
void	rrb(int *b, int len);
void	rrr(int *a, int *b, int len_a, int len_b);
long	ft_atoi(const char *str);
void	sort(int *stack_a, int size_a);
int		min(int *stack, int size);
int		diff(t_operations min, t_operations op);

typedef struct s_operations
{
	int	pa;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_operations;

#endif