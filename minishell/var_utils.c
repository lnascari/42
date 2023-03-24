/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:07:55 by gpaoline          #+#    #+#             */
/*   Updated: 2023/03/23 14:31:32 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_varclear(t_var **var)
{
	t_var	*tmp;
	t_var	*tmp2;

	tmp = *var;
	if (tmp != 0)
	{
		while (tmp)
		{
			free(tmp->name);
			free(tmp->value);
			tmp2 = tmp;
			tmp = tmp->next;
			free(tmp2);
		}
		*var = 0;
	}
}

void	ft_vardelone(t_var **var, t_var *v)
{
	t_var	*next;
	t_var	*tmp;

	if (v != 0)
	{
		tmp = *var;
		next = v->next;
		if ((*var) == v)
			*var = (*var)->next;
		else
		{
			while (tmp->next != v)
				tmp = tmp->next;
			tmp->next = next;
		}
		free(v->name);
		free(v->value);
		free(v);
	}
}

void	ft_varadd_front(t_var **var, char *name, char *value, int export)
{
	t_var	*new;

	new = malloc(sizeof(t_var));
	new->name = name;
	new->value = value;
	new->export = export;
	new->next = NULL;
	if (var)
	{
		if (*var == 0)
			*var = new;
		else
		{
			new->next = *var;
			*var = new;
		}
	}
}

t_var	*ft_varsearch(t_var *var, char *name)
{
	while (var && ft_strcmp(var->name, name) != 0)
		var = var->next;
	if (!var)
		return (0);
	return (var);
}

void	ft_varedit(t_var **var, char *name, char *value, int export)
{
	t_var	*v;

	v = ft_varsearch(*var, name);
	if (v)
	{
		free(name);
		free(v->value);
		v->value = value;
	}
	else
		ft_varadd_front(var, name, value, export);
}
