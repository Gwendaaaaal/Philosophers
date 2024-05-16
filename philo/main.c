/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:20:23 by gholloco          #+#    #+#             */
/*   Updated: 2024/05/15 21:34:41 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (parse(&data, argc, argv))
		return(1);
	init_data(&data);
	init_forks(&data);
	init_philosophers(&data);	
	clean_threads(&data);
}
