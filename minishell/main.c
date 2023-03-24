/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:21:22 by gpaoline          #+#    #+#             */
/*   Updated: 2023/03/24 11:36:57 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cases(char **s, char *str)
{
	int	i;

	i = -1;
	while (s[++i] && var_value(s[i], 0))
		;
	if (!ft_strcmp(s[0], "exit"))
		ft_exit(s, str);
	else if (!ft_strcmp(s[0], "env"))
		ft_env();
	else if (!ft_strcmp(s[0], "export"))
		ft_export(s);
	else if (!ft_strcmp(s[0], "unset"))
		ft_unset(s);
	else if (!ft_strcmp(s[0], "cd"))
		ft_cd(s);
	else
		programs(s);
}

void	routine(char *str)
{
	char	**s;

	space_in_quote(str);
	del_quote(str);
	s = ft_split(str, ' ');
	spaces(s);
	check_var(s);
	cases(s, str);
	ft_free_split(s);
	add_history(str);
	free(str);
}

int	main(void)
{
	struct termios	t;
	extern t_var	*g_var;
	char			*str;

	signal(SIGINT, handler_int);
	signal(SIGQUIT, handler_quit);
	tcgetattr(0, &t);
	t.c_cc[VQUIT] = 0;
	tcsetattr(0, TCSANOW, &t);
	g_var = 0;
	ft_varadd_front(&g_var, ft_strcpy("?"), ft_strcpy("0"), 0);
	while (1)
	{
		str = readline("minishell> ");
		if (!str)
			ft_exit(0, 0);
		if (str[0])
			routine(str);
	}
}
