/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:54:12 by lnascari          #+#    #+#             */
/*   Updated: 2023/01/13 11:54:36 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	int	bit;

	if (argc == 3)
	{
		pid = atoi(argv[1]);
		i = -1;
		while (argv[2][++i])
		{
			bit = 0;
			while (bit < 8)
			{
				if (argv[2][i] & 0b10000000)
					kill(pid, SIGUSR2);
				else
					kill(pid, SIGUSR1);
				argv[2][i] = argv[2][i] << 1;
				bit++;
			}
		}
	}
}
