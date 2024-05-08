/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:25:09 by gholloco          #+#    #+#             */
/*   Updated: 2024/05/08 16:32:43 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_data t_data;

typedef struct s_philo
{
	int				index;
	pthread_t		id;
	t_data			*data;
} t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				needed_lunchs;
	long int		start_time;
	t_philo			*philosophers;
	pthread_mutex_t	**forks;
} t_data;

// init.c
int	init_forks(t_data *data);
int	init_philosophers(t_data *data);

// parse.c
int	parse(t_data *data, int argc, char **args);

// philo.c
void *thread_routine(void *data);

// utils.c
int			ft_atoi(const char *nptr);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
long int	get_timestamp_in_ms(void);

#endif
