/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:04:28 by gholloco          #+#    #+#             */
/*   Updated: 2024/11/27 16:44:44 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	shift_philos(t_philo *philo)
{
	if (philo->index % 2)
	{
		write_message(philo->data, philo->index, THINK);
		usleep((philo->data->time_to_eat - 1) * 1000);
	}
}

void	shift_philoss(t_philo *philo)
{
	if (philo->data->nb_philo % 2 && philo->index == philo->data->nb_philo)
	{
		usleep((philo->data->time_to_eat - 1) * 2000);
	}
	else if (philo->index % 2)
	{
		usleep((philo->data->time_to_eat - 1) * 1000);
	}
}

void	*thread_routine(void *data)
{
	t_philo	*philo;
	int		sleep;
	int		tte;
	int		tts;

	philo = data;
	shift_philos(philo);
	while (!stop(philo->data))
	{
		if (!stop(philo->data))
			eat(philo);
		if (!stop(philo->data))
		{
			write_message(philo->data, philo->index, SLEEP);
			ft_sleep(philo->data->time_to_sleep, philo);
			write_message(philo->data, philo->index, THINK);
			tte = philo->data->time_to_eat;
			tts = philo->data->time_to_sleep;
			if (philo->data->nb_philo % 2)
			{
				sleep = (tte * 2) - tts - 1;
				if (sleep >= 0)
					ft_sleep(sleep, philo);
			}
		}
	}
	return (NULL);
}
