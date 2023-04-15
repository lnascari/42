/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:17:49 by gpaoline          #+#    #+#             */
/*   Updated: 2023/04/14 12:21:35 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	operators(char *str)
{
	if (!ft_strcmp(str, "<"))
		return (1);
	if (!ft_strcmp(str, ">"))
		return (2);
	if (!ft_strcmp(str, "<<"))
		return (3);
	if (!ft_strcmp(str, ">>"))
		return (4);
	return (0);
}

void	file_op(char *str, int op, int *error)
{
	int	fd;

	if (op == 1)
	{
		if (access(str, F_OK) == -1)
			ft_error(error, str, 0);
		else
		{
			if (access(str, R_OK) == -1)
				ft_error(error, str, 0);
		}
	}
	else if (op == 2 || op == 4)
	{
		if (op == 2)
			fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else
			fd = open(str, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
			ft_error(error, str, 0);
		else
			close(fd);
	}
}

void	op_flags(char *str, int op, t_red *order)
{
	if (op == 1 || op == 3)
	{
		if (op == 1)
			order->input = 1;
		else
			order->input = 2;
		if (order->input_file)
			free(order->input_file);
		order->input_file = ft_strdup(str);
	}
	else if (op == 2 || op == 4)
	{
		if (op == 2)
			order->output = 1;
		else
			order->output = 2;
		if (order->output_file)
			free(order->output_file);
		order->output_file = ft_strdup(str);
	}
}

void	not_op(t_red *order, int len, char **s)
{
	int	i;
	int	j;

	order->s = (char **)malloc((len + 1) * sizeof(char *));
	i = -1;
	j = -1;
	while (s[++i] && j < len)
	{
		if (!operators(s[i]))
			order->s[++j] = ft_strdup(s[i]);
		else
			i++;
	}
	order->s[len] = 0;
	if (!cases_control(order->s))
	{
		ft_error(0, order->s[0], 1);
		ft_free_split(order->s, 1);
		order->s = 0;
	}
}

void	redirections(char **s, t_red *order)
{
	int		i;
	int		len;
	int		error;

	red_struct_init(order);
	i = -1;
	len = 0;
	error = 0;
	while (s[++i])
	{
		if (operators(s[i]))
		{
			file_op(s[i + 1], operators(s[i]), &error);
			op_flags(s[i + 1], operators(s[i]), order);
			if (s[i + 1])
				i++;
		}
		else
			len++;
	}
	if (!error)
		not_op(order, len, s);
	ft_free_split(s, 0);
}
