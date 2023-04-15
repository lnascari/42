/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:22:34 by gpaoline          #+#    #+#             */
/*   Updated: 2023/04/14 12:22:54 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	red_struct_init(t_red *order)
{
	order->input = 0;
	order->input_file = 0;
	order->output = 0;
	order->output_file = 0;
	order->s = 0;
}

int	struct_error(t_red *orders, int pipes)
{
	int	i;

	i = -1;
	while (++i < pipes + 1)
	{
		if (!orders[i].s)
		{
			ft_free_struct(orders, pipes);
			return (1);
		}
	}
	return (0);
}

void	del_pipes(char **s, int *pipes)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!ft_strcmp(s[i], "|"))
		{
			*pipes += 1;
			free(s[i]);
			s[i] = 0;
		}
	}
}

void	orders_arr(char **s, char *str)
{
	t_red	*orders;
	int		pipes;
	int		i;
	int		j;

	pipes = 0;
	del_pipes(s, &pipes);
	orders = malloc((pipes + 1) * sizeof(t_red));
	i = -1;
	j = 0;
	while (++i < pipes + 1)
	{
		redirections(&s[j], &orders[i]);
		while (s[j])
			j++;
		j++;
	}
	free(s);
	exec_op(orders, pipes, str);
}
