/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:10:20 by gpaoline          #+#    #+#             */
/*   Updated: 2023/04/14 12:16:50 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*file_name(int i)
{
	char	*name;
	char	*tmp;

	name = ft_itoa(i);
	tmp = name;
	name = ft_strjoin(".", name);
	free(tmp);
	return (name);
}

void	input_end(int i, int *stdin_backup)
{
	int		fd;
	char	*name;

	*stdin_backup = dup(0);
	name = file_name(i - 1);
	fd = open(name, O_RDONLY | O_CREAT, 0644);
	free(name);
	dup2(fd, 0);
}

void	exec_pipe(t_red *orders, char *str, int i, int pipes)
{
	char	*name;
	int		stdin_backup;
	int		stdout_backup;
	int		pid;
	int		fd;

	pid = fork();
	if (!pid)
	{
		if (i)
			input_end(i, &stdin_backup);
		stdout_backup = dup(1);
		name = file_name(i);
		fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		free(name);
		dup2(fd, 1);
		open_and_exec(orders[i]);
		if (i)
			dup2(0, stdin_backup);
		dup2(1, stdout_backup);
		ft_free_and_exit(orders, str, pipes);
	}
	waitpid(pid, 0, 0);
}

void	last_command(t_red *orders, char *str, int i, int pipes)
{
	int	stdin_backup;
	int	pid;

	pid = fork();
	if (!pid)
	{
		input_end(i, &stdin_backup);
		open_and_exec(orders[i]);
		dup2(0, stdin_backup);
		ft_free_and_exit(orders, str, pipes);
	}
	waitpid(pid, 0, 0);
}

void	exec_op(t_red *orders, int pipes, char *str)
{
	char	*name;
	int		i;

	if (!struct_error(orders, pipes))
	{
		if (!pipes)
			open_and_exec(orders[0]);
		else
		{
			i = -1;
			while (++i < pipes)
				exec_pipe(orders, str, i, pipes);
			last_command(orders, str, i, pipes);
			i = -1;
			while (++i < pipes)
			{
				name = file_name(i);
				unlink(name);
				free(name);
			}
		}
		ft_free_struct(orders, pipes);
	}
}
