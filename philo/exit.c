/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:40:05 by gholloco          #+#    #+#             */
/*   Updated: 2024/05/17 16:33:29 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_everything(t_data *data)
{
	int	i;

	clean_threads(data);
	i = -1;
	while (++i < data->nb_philo)
	{
		pthread_mutex_destroy(data->forks[i]);
		free(data->forks[i]);
	}
	pthread_mutex_destroy(&data->write_mutex);
	free(data->forks);
	free(data->philosophers);
	return (0);
}

int	clean_threads(t_data *data)
{
	int	i;
	
	i = -1;
	while (++i < data->nb_philo)
	{
		pthread_join(data->philosophers[i].id, NULL);
	}
	return (0);
}
