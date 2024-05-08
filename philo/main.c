/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:20:23 by gholloco          #+#    #+#             */
/*   Updated: 2024/05/08 16:49:31 by gholloco         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_data	data;

	if (parse(&data, argc, argv))
		return(1);
	init_forks(&data);
	init_philosophers(&data);	
	clean_threads(&data);
}
