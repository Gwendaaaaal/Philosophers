/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:24:06 by gholloco          #+#    #+#             */
/*   Updated: 2024/11/27 17:25:42 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	stop(t_data *data)
{
	int stop;

	pthread_mutex_lock(&data->stop_mutex);
	stop = data->stop;
	pthread_mutex_unlock(&data->stop_mutex);
	return (stop);
}

int	enough_lunchs(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		pthread_mutex_lock(&data->philosophers[i].enough_lunchs_mutex);
		if (!data->philosophers[i].enough_lunchs)
		{
			pthread_mutex_unlock(&data->philosophers[i].enough_lunchs_mutex);
			return (0);
		}
		pthread_mutex_unlock(&data->philosophers[i].enough_lunchs_mutex);
	}
	pthread_mutex_lock(&data->stop_mutex);
	data->stop = 1;
	pthread_mutex_unlock(&data->stop_mutex);
	return (1);
}

int	death(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_lunch_mutex);
	if (get_timestamp_in_ms() - philo->last_lunch >= philo->data->time_to_die)
	{
		pthread_mutex_unlock(&philo->last_lunch_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->last_lunch_mutex);
	return (0);
}

int	monitor(t_data *data)
{
	int	i;

	i = 0;
	while (!enough_lunchs(data) && !stop(data))
	{
		if (i == data->nb_philo)
			i = 0;
		if (death(&data->philosophers[i]))
		{
			pthread_mutex_lock(&data->stop_mutex);
			data->stop = 1;
			pthread_mutex_unlock(&data->stop_mutex);
			usleep(50);
			write_message(data, data->philosophers[i].index, DEAD);
		}
		usleep(10);
		i++;
	}
	return (0);
}
