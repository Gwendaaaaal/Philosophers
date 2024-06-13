/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:25:09 by gholloco          #+#    #+#             */
/*   Updated: 2024/06/13 10:37:19 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>

# define EAT 100
# define FORK 101
# define SLEEP 102
# define THINK 103
# define DEAD 104

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				index;
	int				nb_lunchs;
	int				enough_lunchs;
	long int		last_lunch;
	pthread_t		id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	enough_lunchs_mutex;
	pthread_mutex_t	last_lunch_mutex;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				needed_lunchs;
	int				stop;
	long int		start_time;
	t_philo			*philosophers;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	**forks;
}	t_data;

// actions.c
int			take_forks(t_philo *philo);
int			take_left_fork(t_philo *philo);
int			take_right_fork(t_philo *philo);
int			drop_forks(t_philo *philo);
int			eat(t_philo *philo);
int			nap(t_philo *philo);

// exit.c
int			free_everything(t_data *data);
int			clean_threads(t_data *data);

// init.c
int			init(t_data *data);
int			init_data(t_data *data);
int			init_forks(t_data *data);
int			init_philosophers(t_data *data);

//monitor.c
int			stop(t_data *data);
int			monitor(t_data *data);

// parse.c
int			parse(t_data *data, int argc, char **args);

// philo.c
void		*thread_routine(void *data);

// utils.c
int			ft_atoi(const char *nptr);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
long int	get_timestamp_in_ms(void);
int			write_message(t_data *data, int id, int message);

#endif
