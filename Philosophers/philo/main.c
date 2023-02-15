/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:20:25 by lnascari          #+#    #+#             */
/*   Updated: 2023/02/15 15:14:16 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void*	routine(void* arg)
{
	info_t	*info;

	info = (info_t *) arg;
	pthread_mutex_lock(&info->lock);
	if (info->forks < 2)
	{
		printf("thinking\n");
		while (info->forks < 2)
			pthread_mutex_lock(&info->lock);
	}
	pthread_mutex_unlock(&info->lock);
	
}

int	main(int argc, char **argv)
{
	info_t	info;
	int		i;

	if (argc == 5 || argc == 6)
	{
		
		info.number_of_philosophers = ft_atoi(argv[1]);
		info.philo = malloc(sizeof(philo_t) * info.number_of_philosophers);
		i = -1;
		while (++i < info.number_of_philosophers)
			pthread_create(&info.philo[i].thread, 0, &routine, &info);
		pthread_mutex_init(&info.lock, 0);
		if (argc == 6)
			info.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		else
			info.number_of_times_each_philosopher_must_eat = -1;
		while (info.number_of_times_each_philosopher_must_eat--)
		{
			i = 0;
			while (i < info.number_of_philosophers)
			{
				pthread_join(info.philo[i].thread, 0);
				i +=2;
			}
			i = 1;
			while (i < info.number_of_philosophers)
			{
				pthread_join(info.philo[i].thread, 0);
				i +=2;
			}
		}
	}
}
