/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:15:44 by gholloco          #+#    #+#             */
/*   Updated: 2024/05/16 18:49:13 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *philo)
{
	
}

int	eat(t_philo *philo)
{
	write_message(philo->data, philo->index, EAT);
	philo->nb_lunchs++;
	return (1);
}
