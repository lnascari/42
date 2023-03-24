/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:08:43 by gpaoline          #+#    #+#             */
/*   Updated: 2023/03/24 11:20:34 by gpaoline         ###   ########.fr       */
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

void	check_quote(char *str, int i, int *squote, int *dquote)
{
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
