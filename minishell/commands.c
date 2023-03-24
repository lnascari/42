/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:25:31 by gpaoline          #+#    #+#             */
/*   Updated: 2023/03/24 11:37:32 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(void)
{
	extern char	**environ;
	t_var		*v;
	int			i;

	i = 0;
	while (environ[i])
		printf("%s\n", environ[i++]);
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
		ft_free_split(s);
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
		if (!ft_strcmp(s[1], "-"))
		{
			if (chdir(getenv("OLDPWD")))
				printf("Error\n");
			else
				printf("%s\n", getenv("OLDPWD"));
		}
		else if (chdir(s[1]))
			printf("Error\n");
	}
	else
		chdir(getenv("HOME"));
}
