/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:37:19 by gholloco          #+#    #+#             */
/*   Updated: 2024/06/13 10:39:08 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (n > 0 && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (((unsigned char) s1[i]) - ((unsigned char) s2[i]));
		n--;
		i++;
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	minus;

	i = 0;
	res = 0;
	minus = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - 48);
		i++;
	}
	return (res * minus);
}

long int	get_timestamp_in_ms(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) < 0)
		return (0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	write_message(t_data *data, int id, int message)
{
	long int	time;

	if (stop(data))
		return (1);
	time = get_timestamp_in_ms();
	if (!time)
		return (1);
	pthread_mutex_lock(&data->write_mutex);
	if (message == EAT)
		printf("%ld %d is eating\n", time - data->start_time, id);
	else if (message == THINK)
		printf("%ld %d is thinking\n", time - data->start_time, id);
	else if (message == SLEEP)
		printf("%ld %d is sleeping\n", time - data->start_time, id);
	else if (message == FORK)
		printf("%ld %d has taken a fork\n", time - data->start_time, id);
	else if (message == DEAD)
		printf("%ld %d died\n", time - data->start_time, id);
	pthread_mutex_unlock(&data->write_mutex);
	return (0);
}
