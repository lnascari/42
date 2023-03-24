/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:21:52 by gpaoline          #+#    #+#             */
/*   Updated: 2023/03/24 11:23:17 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	new_str(char **str, char *value, int start, int end)
{
	int		i;
	int		j;
	char	*new;

	new = malloc((ft_strlen(*str) - (end - start)) + ft_strlen(value) + 1);
	i = -1;
	j = -1;
	while (++i < start)
		new[++j] = (*str)[i];
	i = -1;
	while (value[++i])
		new[++j] = value[i];
	i = end - 1;
	while ((*str)[++i])
		new[++j] = (*str)[i];
	new[++j] = 0;
	free(*str);
	*str = new;
}

void	alnum_var(char **str, int start)
{
	extern t_var	*g_var;
	t_var			*v;
	char			*name;
	int				i;
	int				end;

	i = start + 1;
	while ((*str)[i] == '_' || ft_isalnum((*str)[i]))
		i++;
	end = i;
	name = ft_substr(*str, start + 1, end - (start + 1));
	if (getenv(name))
		new_str(str, getenv(name), start, end);
	else
	{
		v = ft_varsearch(g_var, name);
		if (v)
			new_str(str, v->value, start, end);
		else
			new_str(str, "", start, end);
	}
	free(name);
}

int	sub_var(char **str, int start)
{
	extern t_var	*g_var;
	t_var			*v;
	int				i;
	

	i = start + 1;
	if ((*str)[i] == '?' || (*str)[i] == '_' || ft_isalnum((*str)[i]))
	{
		if ((*str)[i] == '?')
		{
			v = ft_varsearch(g_var, "?");
			new_str(str, v->value, start, start + 2);
		}
		else
			alnum_var(str, start);
		return (1);
	}
	return (0);
}

void	check_var(char **s)
{
	int	i;
	int	j;

	i = -1;
	while (s[++i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == '$')
			{
				if (sub_var(&s[i], j))
					j--;
			}
			else if (s[i][j] == 18)
				s[i][j] = '$';
			j++;
		}
	}
}

int	var_value(char *str, int export)
{
	extern t_var	*g_var;
	char			*name;
	char			*value;
	int				i;

	i = 0;
	while (str[i] == '_' || (str[i] >= '0' && str[i] <= '9')
		|| (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		i++;
	if (i && str[i] == '=')
	{
		name = malloc(i + 1);
		ft_strlcpy(name, str, i + 1);
		value = malloc(ft_strlen(str) - i);
		ft_strlcpy(value, str + i + 1, ft_strlen(str) - i);
		ft_varedit(&g_var, name, value, export);
		return (1);
	}
	return (0);
}
