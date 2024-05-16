/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:40:05 by gholloco          #+#    #+#             */
/*   Updated: 2024/05/15 19:40:14 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
