/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:25:31 by gpaoline          #+#    #+#             */
/*   Updated: 2023/05/03 12:47:44 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(void)
{
	t_var		*v;

	v = g_var;
	while (v)
	{
		if (v->export)
			printf("%s=%s\n", v->name, v->value);
		v = v->next;
	}
}

void	ft_export(char **s)
{
	t_var	*v;
	int		i;

	i = 0;
	if (!s[1])
		ft_env();
	else
	{
		while (s[++i])
		{
			if (!var_value(s[i], 1) && s[i][0] != '?')
			{
				v = ft_varsearch(g_var, s[i]);
				if (v)
					v->export = 1;
			}
		}
	}
}

void	ft_unset(char **s)
{
	t_var	*v;
	int		i;

	i = 0;
	while (s[++i] && s[i][0] != '?')
	{
		v = ft_varsearch(g_var, s[i]);
		if (v)
			ft_vardelone(&g_var, v);
	}
}

void	ft_exit(char **s, char *str)
{
	int	n;

	n = ft_atoi(g_var->value);
	if (s)
	{
		free(str);
		if (s[1])
			n = ft_atoi(s[1]);
		ft_free_split(s, 1);
	}
	ft_varclear(&g_var);
	rl_clear_history();
	printf("exit\n");
	exit(n);
}

void	ft_cd(char **s)
{
	if (s[1])
	{
		if (chdir(s[1]))
			perror("Error");
	}
	else
	{
		if (ft_varsearch(g_var, "HOME"))
		{
			if (chdir(ft_varsearch(g_var, "HOME")->value))
				perror("Error");
		}
	}
}
