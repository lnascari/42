/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:21:22 by gpaoline          #+#    #+#             */
/*   Updated: 2023/05/03 12:29:35 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_var	*g_var;

void	ft_error(int *error, char *s, int p)
{
	if (!error || !*error)
	{
		if (p)
		{
			write(2, s, ft_strlen(s));
			write(2, ": command not found\n", 20);
		}
		else
		{
			write(2, "Error: ", 7);
			perror(s);
		}
		if (error)
			*error = 1;
	}
}

int	cases_control(char **s)
{
	int	r;

	r = 1;
	if (!ft_strcmp(s[0], "exit"))
		;
	else if (!ft_strcmp(s[0], "env"))
		;
	else if (!ft_strcmp(s[0], "export"))
		;
	else if (!ft_strcmp(s[0], "unset"))
		;
	else if (!ft_strcmp(s[0], "cd"))
		;
	else
		r = programs(s, 0);
	return (r);
}

int	cases(char **s, char *str)
{
	int	i;
	int	r;
	int	b;

	b = 1;
	r = 1;
	i = -1;
	while (s[++i] && var_value(s[i], 0))
		b = 0;
	if (b && !ft_strcmp(s[0], "exit"))
		ft_exit(s, str);
	else if (b && !ft_strcmp(s[0], "env"))
		ft_env();
	else if (b && !ft_strcmp(s[0], "export"))
		ft_export(s);
	else if (b && !ft_strcmp(s[0], "unset"))
		ft_unset(s);
	else if (b && !ft_strcmp(s[0], "cd"))
		ft_cd(s);
	else if (b)
		r = programs(s, 1);
	return (r);
}

void	routine(char *str)
{
	char	**s;

	add_history(str);
	space_in_quote(str);
	del_quote(str);
	s = ft_split(str, ' ');
	spaces(s);
	check_var(s);
	if (!op_pipe_check(s))
		no_op_case(s, str);
	else
	{
		if (op_pipe_error(s))
		{
			ft_free_split(s, 1);
			write(2, "Error: Invalid argument\n", 24);
		}
		else
		{
			replace_op(s);
			orders_arr(s, str);
		}
	}
	free(str);
}

int	main(void)
{
	struct termios	t;
	extern t_var	*g_var;
	char			*str;
	extern char		**environ;

	signal(SIGINT, handler_int);
	signal(SIGQUIT, handler_quit);
	tcgetattr(0, &t);
	t.c_cc[VQUIT] = 0;
	tcsetattr(0, TCSANOW, &t);
	g_var = 0;
	ft_varadd_front(&g_var, ft_strcpy("?"), ft_strcpy("0"), 0);
	ft_new_environ(environ);
	while (1)
	{
		str = readline("minishell> ");
		if (!str)
			ft_exit(0, 0);
		if (all_spaces(str))
			continue ;
		if (str[0])
			routine(str);
	}
}
