/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:14:01 by gpaoline          #+#    #+#             */
/*   Updated: 2023/04/17 14:20:11 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc(int fdi, t_red orders)
{
	char	*str;

	while (1)
	{
		str = readline("> ");
		if (!str)
		{
			printf("\n");
			continue ;
		}
		if (!ft_strcmp(str, orders.input_file))
			break ;
		write(fdi, str, ft_strlen(str));
		write(fdi, "\n", 1);
		free(str);
	}
	free(str);
}

void	open_input(int *fdi, t_red orders)
{
	int		stdout_backup;

	if (orders.input == 2)
	{
		*fdi = open(".heredoc", O_RDWR | O_CREAT | O_TRUNC, 0644);
		stdout_backup = dup(1);
		dup2(orders.s_in, 0);
		dup2(orders.s_out, 1);
		heredoc(*fdi, orders);
		close(*fdi);
		dup2(stdout_backup, 1);
		close(stdout_backup);
		*fdi = open(".heredoc", O_RDONLY, 0644);
	}
	else
		*fdi = open(orders.input_file, O_RDONLY, 0644);
}

void	open_ouput(int *fdo, int *stdout_backup, t_red orders)
{
	if (orders.output == 1)
		*fdo = open(orders.output_file, O_WRONLY | O_TRUNC, 0644);
	else
		*fdo = open(orders.output_file, O_WRONLY | O_APPEND, 0644);
	*stdout_backup = dup(1);
	dup2(*fdo, 1);
	close(*fdo);
}

void	close_io(int fdi, int fdo, int stdin_backup, int stdout_backup)
{
	if (fdi)
	{
		dup2(stdin_backup, 0);
		close(stdin_backup);
		if (!access(".heredoc", F_OK))
			unlink(".heredoc");
	}
	if (fdo)
	{
		dup2(stdout_backup, 1);
		close(stdout_backup);
	}
}

void	open_and_exec(t_red orders)
{
	int	fdi;
	int	stdin_backup;
	int	fdo;
	int	stdout_backup;

	fdi = 0;
	fdo = 0;
	if (orders.input)
	{
		stdin_backup = dup(0);
		open_input(&fdi, orders);
		dup2(fdi, 0);
		close(fdi);
	}
	else
		stdin_backup = 0;
	if (orders.output)
		open_ouput(&fdo, &stdout_backup, orders);
	else
		stdout_backup = 0;
	programs(orders.s, 1);
	close_io(fdi, fdo, stdin_backup, stdout_backup);
}
