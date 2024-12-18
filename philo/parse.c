/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:28:48 by gholloco          #+#    #+#             */
/*   Updated: 2024/11/28 15:05:19 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static int	check_args(char **argv)
{
	int	i;
	int	num_len;

	i = 1;
	while (argv[i])
	{
		if (check_number(argv[i]))
			return (1);
		num_len = 0;
		while (argv[i][num_len])
			num_len++;
		if (num_len == 1 && !ft_strncmp(argv[i], "0", 2))
			return (1);
		if (num_len == 10 && ft_strncmp(argv[i], "2147483647", 10) > 0)
			return (1);
		if (num_len >= 11)
			return (1);
		i++;
	}
	return (0);
}

int	parse(t_data *data, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (printf("Wrong number of arguments\n"), 1);
	if (check_args(argv))
		return (printf("Wrong types of arguments\n"), 1);
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->needed_lunchs = ft_atoi(argv[5]);
	else
		data->needed_lunchs = -1;
	return (0);
}
