/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:07:05 by gpaoline          #+#    #+#             */
/*   Updated: 2023/05/03 13:20:04 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	environ_to_var(char *name, char *value, char *env_str)
{
	int	i;
	int	j;

	i = -1;
	while (env_str[++i] != '=')
		name[i] = env_str[i];
	name[i] = 0;
	j = -1;
	while (env_str[++i])
		value[++j] = env_str[i];
	value[j + 1] = 0;
	ft_varadd_front(&g_var, name, value, 1);
}

void	ft_new_environ(char **environ)
{
	int		len;
	int		i;
	int		j;
	char	*name;
	char	*value;

	len = -1;
	while (environ[++len])
	{
		i = -1;
		while (environ[len][++i] != '=')
			;
		name = (char *)malloc(i + 1);
		j = i;
		while (environ[len][++i])
			;
		value = (char *)malloc(i - j);
		environ_to_var(name, value, environ[len]);
	}
}
