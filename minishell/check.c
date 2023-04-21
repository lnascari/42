/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:01:00 by gpaoline          #+#    #+#             */
/*   Updated: 2023/04/21 11:12:48 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	op_pipe_check(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (operators(s[i]) || !ft_strcmp(s[i], "|"))
			return (1);
	}
	return (0);
}

int	op_pipe_error(char **s)
{
	int	i;

	if (!ft_strcmp(s[0], "|"))
		return (1);
	i = -1;
	while (s[++i + 1])
	{
		if ((operators(s[i]) || !ft_strcmp(s[i], "|"))
			&& (operators(s[i + 1]) || !ft_strcmp(s[i + 1], "|")))
			return (1);
	}
	if (operators(s[i]) || !ft_strcmp(s[i], "|"))
		return (1);
	return (0);
}

int	is_directory(char *s)
{
	struct stat	buf;

	stat(s, &buf);
	if (!s[0])
		return (1);
	return (S_ISDIR(buf.st_mode));
}

int	all_spaces(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != ' ')
			return (0);
	}
	free (str);
	return (1);
}
