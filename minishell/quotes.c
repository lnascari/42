/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:08:43 by gpaoline          #+#    #+#             */
/*   Updated: 2023/05/02 13:35:02 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	space_in_quote(char *str)
{
	int	i;
	int	squote;
	int	dquote;

	i = -1;
	squote = 0;
	dquote = 0;
	while (str[++i])
	{
		if (!squote && str[i] == '"')
			dquote = !dquote;
		if (!dquote && str[i] == '\'')
			squote = !squote;
		if (dquote && str[i] == ' ')
			str[i] = 17;
		if (squote && str[i] == ' ')
			str[i] = 17;
	}
}

void	replace_op(char **s)
{
	int	i;
	int	j;

	j = -1;
	while (s[++j])
	{
		i = -1;
		while (s[j][++i])
		{
			if (s[j][i] == 16)
				s[j][i] = '|';
			if (s[j][i] == 19)
				s[j][i] = '>';
			if (s[j][i] == 20)
				s[j][i] = '<';
		}
	}
}

void	op_in_quote(char *str, int i)
{
	if (str[i] == '|')
		str[i] = 16;
	if (str[i] == '>')
		str[i] = 19;
	if (str[i] == '<')
		str[i] = 20;
}

void	check_quote(char *str, int i, int *squote, int *dquote)
{
	if (*squote || *dquote)
		op_in_quote(str, i);
	if (*squote && str[i] == '$')
		str[i] = 18;
	if (!(*squote) && str[i] == '"')
	{
		*dquote = !(*dquote);
		if (!(*dquote) && str[i] == '"')
			str[i] = 127;
	}
	if (!(*dquote) && str[i] == '\'')
	{
		*squote = !(*squote);
		if (!(*squote) && str[i] == '\'')
			str[i] = 127;
	}
	if (*dquote && str[i] == '"')
		str[i] = 127;
	if (*squote && str[i] == '\'')
		str[i] = 127;
}

void	del_quote(char *str)
{
	int	i;
	int	squote;
	int	dquote;

	i = -1;
	squote = 0;
	dquote = 0;
	while (str[++i])
		check_quote(str, i, &squote, &dquote);
}
