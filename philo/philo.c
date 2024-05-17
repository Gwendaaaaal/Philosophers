/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:04:28 by gholloco          #+#    #+#             */
/*   Updated: 2024/05/17 19:56:06 by gholloco         ###   ########.fr       */
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
	while (philo->nb_lunchs != philo->data->needed_lunchs)
	{
		if (!philo->data->stop)
			take_forks(philo);
		if (!philo->data->stop)
			eat(philo);
		if (!philo->data->stop)
			nap(philo);
	}
	return (NULL);
}
