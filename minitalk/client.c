/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:54:12 by lnascari          #+#    #+#             */
/*   Updated: 2023/01/16 16:20:36 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum)
{
	if (signum == SIGUSR1)
		write(1, "\nReceived\n\n", 12);
}

void	send_null(int pid)
{
	int	i;

	i = 0;
	while (i++ < 8)
	{
		usleep(100);
		kill(pid, SIGUSR1);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	int	bit;

	if (argc == 3)
	{
		signal(SIGUSR1, &handler);
		pid = ft_atoi(argv[1]);
		i = -1;
		while (argv[2][++i])
		{
			bit = -1;
			while (++bit < 8)
			{
				if (argv[2][i] & 0b10000000)
					kill(pid, SIGUSR2);
				else
					kill(pid, SIGUSR1);
				argv[2][i] = argv[2][i] << 1;
				usleep(100);
			}
			usleep(500);
		}
		send_null(pid);
	}
}
