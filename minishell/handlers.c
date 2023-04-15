/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:36:58 by gpaoline          #+#    #+#             */
/*   Updated: 2023/04/06 13:30:37 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler_int(int x)
{
	(void) x;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	handler_int_programs(int x)
{
	(void) x;
	printf("\n");
}

void	handler_quit(int x)
{
	(void) x;
}
