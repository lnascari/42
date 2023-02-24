/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:54:25 by lnascari          #+#    #+#             */
/*   Updated: 2023/02/24 11:17:31 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum, siginfo_t *info, void *context)
{
	static int	x;
	static char	c;

	(void) context;
	if (signum == SIGUSR2)
		c = c | 1;
	if (x != 7)
		c = c << 1;
	x++;
	if (x == 8)
	{
		x = 0;
		if (c != 0)
			write(1, &c, 1);
		else
			kill(info->si_pid, SIGUSR1);
		c = 0;
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
