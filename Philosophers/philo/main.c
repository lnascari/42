/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:20:25 by lnascari          #+#    #+#             */
/*   Updated: 2023/04/03 12:43:57 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	data(t_info *info, int n)
{
	int	i;

	i = -1;
	pthread_mutex_init(&info->dmutex, 0);
	while (++i < info->nop)
	{
		pthread_mutex_init(&info->philo[i].rfork, 0);
		if (i == info->nop - 1)
			info->philo[i].lfork = &info->philo[0].rfork;
		else
			info->philo[i].lfork = &info->philo[i + 1].rfork;
		info->philo[i].last_meal = 0;
		info->philo[i].pos = i + 1;
		info->philo[i].info = info;
		info->philo[i].notepme = n;
	}
}

void	threads(t_info *info)
{
	int	i;

	pthread_create(&info->dthread, 0, &check_death, info);
	i = 0;
	while (i < info->nop)
	{
		pthread_create(&info->philo[i].thread, 0, &routine, info->philo + i);
		i += 2;
		usleep(1);
	}
	i = 1;
	while (i < info->nop)
	{
		pthread_create(&info->philo[i].thread, 0, &routine, info->philo + i);
		i += 2;
		usleep(1);
	}
	pthread_join(info->dthread, 0);
	i = -1;
	while (++i < info->nop)
		pthread_join(info->philo[i].thread, 0);
	free(info->philo);
}

int	main(int argc, char **argv)
{
	struct timeval	tv;
	t_info			info;
	int				n;

	if (argc == 5 || argc == 6)
	{
		info.nop = ft_atoi(argv[1]);
		info.ttd = ft_atoi(argv[2]);
		info.tte = ft_atoi(argv[3]);
		info.tts = ft_atoi(argv[4]);
		if (argc == 6)
			n = ft_atoi(argv[5]);
		else
			n = -1;
		info.philo = malloc(sizeof(t_philo) * info.nop);
		gettimeofday(&tv, 0);
		info.time = tv.tv_sec * 1000000 + tv.tv_usec;
		info.death = 0;
		data(&info, n);
		threads(&info);
	}
}
