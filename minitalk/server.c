/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:54:25 by lnascari          #+#    #+#             */
/*   Updated: 2023/01/13 11:59:43 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

char	g_c;

int	handler(int signum)
{
	static int	x;

	if (x == 8)
	{
		x = 0;
		write(1, &g_c, 1);
	}
	else
		x++;
	if (signum == SIGUSR1)
	{
		printf("Received 1!\n");
		g_c = g_c << 1;
	}
	if (signum == SIGUSR2)
	{
		printf("Received 2!\n");
		g_c = g_c | 1;
		g_c = g_c << 1;
	}
}

int	main(void)
{
	struct sigaction	action;
	struct sigaction	old;

	action.sa_handler = &handler;
	old.sa_handler = &handler;
}
