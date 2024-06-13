/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:04:28 by gholloco          #+#    #+#             */
/*   Updated: 2024/06/13 10:38:51 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	shift_philos(t_philo *philo)
{
	if (philo->index % 2)
	{
		usleep(philo->data->time_to_eat * 1000);
	}
}

void	*thread_routine(void *data)
{
	t_philo	*philo;

	philo = data;
	shift_philos(philo);
	while (philo->nb_lunchs != philo->data->needed_lunchs && !stop(philo->data))
	{
		if (!stop(philo->data))
			eat(philo);
		if (!stop(philo->data))
		{
			write_message(philo->data, philo->index, SLEEP);
			usleep(philo->data->time_to_sleep * 1000);
			write_message(philo->data, philo->index, THINK);
		}
	}
	return (NULL);
}
