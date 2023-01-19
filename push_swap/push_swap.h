/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:01:08 by lnascari          #+#    #+#             */
/*   Updated: 2023/01/19 12:22:39 by lnascari         ###   ########.fr       */
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

#endif