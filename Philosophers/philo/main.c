/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:20:25 by lnascari          #+#    #+#             */
/*   Updated: 2023/02/23 13:01:35 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	struct timeval	tv;
	t_philo			*philo;

	philo = (t_philo *) arg;
	while (philo->number_of_times_each_philosopher_must_eat--)
	{
		pthread_mutex_lock(philo->info->lock);
		gettimeofday(&tv, 0);
		if (philo->info->forks < 2)
			printf ("%ld\t%d is thinking\n", (tv.tv_sec * 1000000
					+ tv.tv_usec - philo->info->time) / 1000, philo->pos);
		pthread_mutex_unlock(philo->info->lock);
		while (1)
		{
			pthread_mutex_lock(philo->info->lock);
			if (philo->info->forks > 1)
			{
				philo->info->forks -= 2;
				pthread_mutex_unlock(philo->info->lock);
				break ;
			}
			pthread_mutex_unlock(philo->info->lock);
		}
		gettimeofday(&tv, 0);
		printf ("%ld\t%d is eating\n", (tv.tv_sec * 1000000
				+ tv.tv_usec - philo->info->time) / 1000, philo->pos);
		usleep(philo->info->time_to_eat * 1000);
		pthread_mutex_lock(philo->info->lock);
		philo->info->forks += 2;
		pthread_mutex_unlock(philo->info->lock);
		gettimeofday(&tv, 0);
		printf ("%ld\t%d is sleeping\n", (tv.tv_sec * 1000000
				+ tv.tv_usec - philo->info->time) / 1000, philo->pos);
		usleep(philo->info->time_to_sleep * 1000);
	}
}

int	main(int argc, char **argv)
{
	struct timeval	tv;
	t_philo			*philo;
	t_info			info;
	int				i;
	int				n;

	if (argc == 5 || argc == 6)
	{
		info.number_of_philosophers = ft_atoi(argv[1]);
		info.time_to_eat = ft_atoi(argv[3]);
		info.time_to_sleep = ft_atoi(argv[4]);
		info.forks = info.number_of_philosophers;
		if (argc == 6)
			n = ft_atoi(argv[5]);
		else
			n = -1;
		pthread_mutex_init(info.lock, 0);
		philo = malloc(sizeof(t_philo) * info.number_of_philosophers);
		gettimeofday(&tv, 0);
		info.time = tv.tv_sec * 1000000 + tv.tv_usec;
		i = 0;
		while (i < info.number_of_philosophers)
		{
			philo[i].pos = i + 1;
			philo[i].info = &info;
			philo[i].number_of_times_each_philosopher_must_eat = n;
			pthread_create(&philo[i].thread, 0, &routine, philo + i);
			i += 2;
			usleep(1);
		}
		i = 1;
		while (i < info.number_of_philosophers)
		{
			philo[i].pos = i + 1;
			philo[i].info = &info;
			philo[i].number_of_times_each_philosopher_must_eat = n;
			pthread_create(&philo[i].thread, 0, &routine, philo + i);
			i += 2;
			usleep(1);
		}
		i = -1;
		while (++i < info.number_of_philosophers)
			pthread_join(philo[i].thread, 0);
		free(philo);
	}
}
