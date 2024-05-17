/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:24:06 by gholloco          #+#    #+#             */
/*   Updated: 2024/05/17 19:18:14 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int enough_lunchs(t_data *data)
{
	int i;
	
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
	return (1);
}

int	death(t_philo *philo)
{
	if (get_timestamp_in_ms() - philo->last_lunch >= philo->data->time_to_die)	
		return (1);
	return (0);
}

int	monitor(t_data *data)
{
	int	i;

	i = 0;
	while (!enough_lunchs(data) && !data->stop)
	{
		if (i == data->nb_philo)
			i = 0;
		if (death(&data->philosophers[i]))
		{
			write_message(data, data->philosophers[i].index, DEAD);
			data->stop = 1;
		}
		usleep(100);
		i++;
	}
	// printf("On sort de monitor\n");
	return (0);
}
