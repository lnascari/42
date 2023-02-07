/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:01:08 by lnascari          #+#    #+#             */
/*   Updated: 2023/02/07 14:14:00 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# define BUFFER_SIZE 14
# include <unistd.h>
# include <stdlib.h>

typedef struct size
{
	int	size_a;
	int	size_b;
}	t_size;

void	r(int *arr, int len);
void	r_r(int *arr, int len);
void	r_rr(int *a, int *b, int len_a, int len_b);
void	r_rrr(int *a, int *b, int len_a, int len_b);
void	s(int *arr, int len);
void	push_a(int *a, int *b, int *len_a, int *len_b);
void	push_b(int *a, int *b, int *len_a, int *len_b);
void	checker(int *stack_a, int size_a);
int		check_sort(int *stack, int size);
long	ft_atoi(const char *str);
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(const char *s);

#endif