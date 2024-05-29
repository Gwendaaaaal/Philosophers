/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:15:44 by gholloco          #+#    #+#             */
/*   Updated: 2024/05/29 19:28:16 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

// int	take_forks(t_philo *philo)
// {
// 	if (philo->index == philo->data->nb_philo)
// 	{
// 		pthread_mutex_lock(philo->data->forks[philo->index - 1]);
// 		write_message(philo->data, philo->index, FORK);
// 		if (!philo->data->stop)
// 		{
// 			pthread_mutex_lock(philo->data->forks[0]);
// 			write_message(philo->data, philo->index, FORK);
// 		}
// 		else
// 			pthread_mutex_unlock(philo->data->forks[philo->index - 1]);
// 		return (0);
// 	}
// 	pthread_mutex_lock(philo->data->forks[philo->index - 1]);
// 	write_message(philo->data, philo->index, FORK);
// 	pthread_mutex_lock(philo->data->forks[philo->index]);
// 	write_message(philo->data, philo->index, FORK);
// 	return (0);
// }

int take_left_fork(t_philo *philo)
{
	if (!philo->data->stop)
	{
		pthread_mutex_lock(philo->data->forks[philo->index - 1]);
		write_message(philo->data, philo->index, FORK);
	}
	return (0);
}

int	take_right_fork(t_philo *philo)
{
	if (philo->index == philo->data->nb_philo && !philo->data->stop)
	{
		pthread_mutex_lock(philo->data->forks[0]);
		write_message(philo->data, philo->index, FORK);
		return (0);
	}
	if (!philo->data->stop)
	{
		pthread_mutex_lock(philo->data->forks[philo->index]);
		write_message(philo->data, philo->index, FORK);
		return (0);
	}
	pthread_mutex_unlock(philo->data->forks[philo->index - 1]);
	return (0);
}

int	drop_forks(t_philo *philo)
{
	if (philo->index == philo->data->nb_philo)
	{
		// printf("on rentre dans le cas dernier de la table avec %d pour lacher les forks\n", philo->index);
		pthread_mutex_unlock(philo->data->forks[philo->index - 1]);
		pthread_mutex_unlock(philo->data->forks[0]);
		return (0);
	}
	pthread_mutex_unlock(philo->data->forks[philo->index - 1]);
	pthread_mutex_unlock(philo->data->forks[philo->index]);
	return (0);
}
int	eat(t_philo *philo)
{
	write_message(philo->data, philo->index, EAT);
	philo->nb_lunchs++;
	if (philo->nb_lunchs == philo->data->needed_lunchs)
	{
		pthread_mutex_lock(&philo->enough_lunchs_mutex);
		philo->enough_lunchs = 1;
		pthread_mutex_unlock(&philo->enough_lunchs_mutex);
	}
	philo->last_lunch = get_timestamp_in_ms();
	usleep(philo->data->time_to_eat * 1000);
	drop_forks(philo);
	return (0);
}

int	nap(t_philo *philo)
{
	write_message(philo->data, philo->index, SLEEP);
	usleep(philo->data->time_to_sleep * 1000);
	write_message(philo->data, philo->index, THINK);
	return (0);
}
