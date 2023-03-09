/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:55:10 by lnascari          #+#    #+#             */
/*   Updated: 2023/03/09 13:28:23 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*str;

void	handler(int x) {
	(void) x;
	str = readline("\nminishell> ");
	add_history(str);
	free(str);
}

int	main(void)
{
	signal(SIGINT, handler);
	while (1)
	{
		str = readline("minishell> ");
		add_history(str);
		//printf(" ..,,;%s;,,.. ", str);
		free(str);
	}
}
