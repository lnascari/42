/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:29:16 by gpaoline          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/03 12:40:13 by gpaoline         ###   ########.fr       */
=======
/*   Updated: 2023/04/21 11:22:04 by gpaoline         ###   ########.fr       */
>>>>>>> e5fc907b233d9c0130db5a929ee377f265cb5164
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	var_env(char ***env)
{
	char	*tmp;
	t_var	*v;
	int		i;

	i = 0;
	v = g_var;
	while (v)
	{
		if (v->export)
		{
			tmp = ft_strjoin(v->name, "=");
			(*env)[i++] = ft_strjoin(tmp, v->value);
			free(tmp);
		}
		v = v->next;
	}
	(*env)[i] = 0;
}

char	**ft_environ(void)
{
	char		**env;
	t_var		*v;
	int			i;

	i = 0;
	v = g_var;
	while (v)
	{
		if (v->export)
			i++;
		v = v->next;
	}
	env = (char **)(malloc((i + 1) * sizeof(char *)));
	var_env(&env);
	return (env);
}

int	exe_path(char **s, char **p, int i, int exe)
{
	char	*pa;
	char	*temp;
	int		stat;

	temp = ft_strjoin(p[i], "/");
	pa = ft_strjoin(temp, s[0]);
	free(temp);
	if (!access(pa, X_OK) && !is_directory(pa))
	{
		if (exe)
		{
			if (!fork())
				execve(pa, s, ft_environ());
			waitpid(-1, &stat, 0);
			ft_varedit(&g_var, ft_strcpy("?"), ft_itoa(WEXITSTATUS(stat)), 0);
		}
		free(pa);
		return (1);
	}
	free(pa);
	return (0);
}

int	exe_local(char **s, int exe)
{
	int	stat;

	if (!access(s[0], X_OK) && !is_directory(s[0]))
	{
		if (exe)
		{
			if (!fork())
				execve(s[0], s, ft_environ());
			waitpid(-1, &stat, 0);
			ft_varedit(&g_var, ft_strcpy("?"), ft_itoa(WEXITSTATUS(stat)), 0);
		}
		return (1);
	}
	return (0);
}

int	programs(char **s, int exe)
{
	char	**p;
	int		i;
	int		r;

	signal(SIGINT, handler_int_programs);
	r = exe_local(s, exe);
	if (!r)
	{
		if (!ft_varsearch(g_var, "PATH"))
			return (0);
		p = ft_split(ft_varsearch(g_var, "PATH")->value, ':');
		i = -1;
		while (p[++i])
		{
			if (exe_path(s, p, i, exe))
			{
				r = 1;
				break ;
			}
		}
		ft_free_split(p, 1);
	}
	signal(SIGINT, handler_int);
	return (r);
}
