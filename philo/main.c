/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:20:23 by gholloco          #+#    #+#             */
/*   Updated: 2024/04/30 22:30:52 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/select.h>

int	main(int argc, char **argv)
{
	t_settings	settings;
	struct timeval time;

	if (parse(&settings, argc, argv))
		return(1);
	gettimeofday(&time, NULL);
	printf("%ld %ld\n", time.tv_sec, time.tv_usec);
	// print deux fois en foutant un usleep de 1 sec
}
