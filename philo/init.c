/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:25:59 by gholloco          #+#    #+#             */
/*   Updated: 2024/05/17 18:15:13 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	init(t_data *data)
{
	if (init_data(data) || init_forks(data) || init_philosophers(data))
		return (1);
	return (0);
}

int	init_data(t_data *data)
{
	data->start_time = get_timestamp_in_ms();
	data->stop = 0;
	if (!data->start_time)
		return (1);
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	i = -1;
	data->forks = malloc(sizeof(pthread_mutex_t *) * data->nb_philo);
	if (!data->forks)
		return (1);
	while (++i < data->nb_philo)
	{
		data->forks[i] = malloc(sizeof(pthread_mutex_t));
		if (!data->forks[i])
			return (1);
		if (pthread_mutex_init(data->forks[i], NULL))
			return (1);
	}
	if (pthread_mutex_init(&data->write_mutex, NULL))
		return (1);
	return (0);
}

int	init_philosophers(t_data *data)
{
	int	i;

	i = -1;
	data->philosophers = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philosophers)
		return (1);
	while (++i < data->nb_philo)
	{
		data->philosophers[i].index = i + 1;
		data->philosophers[i].nb_lunchs = 0;
		data->philosophers[i].data = data;
		data->philosophers[i].enough_lunchs = 0;
		data->philosophers[i].last_lunch = data->start_time;
		pthread_mutex_init(&data->philosophers[i].enough_lunchs_mutex, NULL);
		pthread_create(&data->philosophers[i].id, NULL, thread_routine, (void *) &data->philosophers[i]);
	}
	return (0);
}
