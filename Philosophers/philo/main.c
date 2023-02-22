/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:20:25 by lnascari          #+#    #+#             */
/*   Updated: 2023/02/22 12:55:56 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void*	routine(void* arg)
{
	philo_t	*philo;

	philo = (philo_t *) arg;
	//while (1)
	//{
		pthread_mutex_lock(philo->info->lock);
		if (philo->info->forks < 2)
			printf ("%d is thinking.\n", philo->pos);
		pthread_mutex_unlock(philo->info->lock);
		while (1)
		{
			pthread_mutex_lock(philo->info->lock);
			printf ("     %d forks\n", philo->info->forks);
			if (philo->info->forks > 1)
			{
				philo->info->forks -= 2;
				pthread_mutex_unlock(philo->info->lock);
				break;
			}
			pthread_mutex_unlock(philo->info->lock);
		}
		
		printf ("%d is eating.\n", philo->pos);
		//usleep(philo->info->time_to_eat * 1000);
		pthread_mutex_lock(philo->info->lock);
		philo->info->forks += 2;
		pthread_mutex_unlock(philo->info->lock);
		printf ("%d is sleeping.\n", philo->pos);
		usleep(philo->info->time_to_sleep * 1000);	
	//}
}

int	main(int argc, char **argv)
{
	philo_t	*philo;
	info_t	info;
	int		i;

	if (argc == 5 || argc == 6)
	{
		
		info.number_of_philosophers = ft_atoi(argv[1]);
		info.time_to_eat = ft_atoi(argv[3]);
		info.time_to_sleep = ft_atoi(argv[4]);
		info.forks = info.number_of_philosophers;
		if (argc == 6)
			info.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		else
			info.number_of_times_each_philosopher_must_eat = -1;
		pthread_mutex_init(info.lock, 0);
		philo = malloc(sizeof(philo_t) * info.number_of_philosophers);
		i = -1;
		while (++i < info.number_of_philosophers)
		{
			philo[i].pos = i + 1;
			philo[i].info = &info;
			pthread_create(&philo[i].thread, 0, &routine, philo + i);
			//usleep(1);
			//pthread_join(philo[i].thread, 0);
		}
	}
}
