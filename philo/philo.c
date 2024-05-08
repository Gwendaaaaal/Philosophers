/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:04:28 by gholloco          #+#    #+#             */
/*   Updated: 2024/05/08 16:46:59 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *thread_routine(void *data)
{
	t_philo	*philo;

	philo = data;
	printf("%d\n", philo->index);
	return (NULL);
}
