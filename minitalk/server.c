/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:54:25 by lnascari          #+#    #+#             */
/*   Updated: 2023/01/16 16:20:07 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	g_c;

void	handler(int signum, siginfo_t *info, void *context)
{
	static int	x;

	(void) context;
	if (signum == SIGUSR2)
		g_c = g_c | 1;
	if (x != 7)
		g_c = g_c << 1;
	x++;
	if (x == 8)
	{
		x = 0;
		if (g_c != 0)
			write(1, &g_c, 1);
		else
			kill(info->si_pid, SIGUSR1);
		g_c = 0;
	}
}

int	main(void)
{
	struct sigaction	action;
	struct sigaction	old_action;
	int					pid;

	action.sa_sigaction = &handler;
	action.sa_flags = SA_SIGINFO;
	pid = getpid();
	write(1, "PID Server: ", 13);
	ft_putnbr(pid);
	write(1, "\n", 2);
	sigaction(SIGUSR2, &action, &old_action);
	sigaction(SIGUSR1, &action, &old_action);
	while (1)
		;
}
