/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:17:03 by gpaoline          #+#    #+#             */
/*   Updated: 2023/03/24 11:20:31 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_127(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == 127)
			count++;
		i++;
	}
	return (count);
}

char	*shorten_list(char *s)
{
	int		i;
	int		j;
	int		count;
	char	*s2;

	count = count_127(s);
	s2 = (char *)malloc(ft_strlen(s) - count + 1);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == 127)
			i++;
		else
		{
			s2[j] = s[i];
			i++;
			j++;
		}
	}
	s2[j] = 0;
	free(s);
	return (s2);
}

void	spaces(char **s)
{
	int	i;
	int	j;

	i = -1;
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
		{
			if (s[i][j] == 17)
				s[i][j] = ' ';
		}
		s[i] = shorten_list(s[i]);
	}
}
