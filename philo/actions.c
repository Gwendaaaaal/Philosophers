/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:15:44 by gholloco          #+#    #+#             */
/*   Updated: 2024/06/13 10:38:56 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	take_forks(t_philo *philo)
{
	if (philo->data->nb_philo == 1)
	{
		take_left_fork(philo);
		while (!stop(philo->data))
			usleep(5000);
		pthread_mutex_unlock(philo->data->forks[philo->index - 1]);
		return (1);
	}
	else if (philo->index % 2)
	{
		take_left_fork(philo);
		take_right_fork(philo);
	}
	else
	{
		take_right_fork(philo);
		take_left_fork(philo);
	}
	return (0);
}

int	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->data->forks[philo->index - 1]);
	write_message(philo->data, philo->index, FORK);
	return (0);
}

int	take_right_fork(t_philo *philo)
{
	if (philo->index == philo->data->nb_philo)
	{
		pthread_mutex_lock(philo->data->forks[0]);
		write_message(philo->data, philo->index, FORK);
		return (0);
	}
	else
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
	if (philo->index % 2)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	return (0);
}

int	eat(t_philo *philo)
{
	if (stop(philo->data))
		return (1);
	if (take_forks(philo))
		return (1);
	write_message(philo->data, philo->index, EAT);
	philo->nb_lunchs++;
	if (philo->nb_lunchs == philo->data->needed_lunchs)
	{
		pthread_mutex_lock(&philo->enough_lunchs_mutex);
		philo->enough_lunchs = 1;
		pthread_mutex_unlock(&philo->enough_lunchs_mutex);
	}
	pthread_mutex_lock(&philo->last_lunch_mutex);
	philo->last_lunch = get_timestamp_in_ms();
	pthread_mutex_unlock(&philo->last_lunch_mutex);
	usleep(philo->data->time_to_eat * 1000);
	drop_forks(philo);
	return (0);
}
