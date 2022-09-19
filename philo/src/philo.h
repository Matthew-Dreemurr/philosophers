/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:21:37 by mahadad           #+#    #+#             */
/*   Updated: 2022/09/19 13:51:38 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

# define PH_BADARG1 "usage: anumber_of_philosophers time_to_die time_to_eat tim"
# define PH_BADARG2 "e_to_sleep [number_of_times_each_philosopher_must_eat]\n"
# define PH_ONEPHILO "need at least one philosopher\n"
# define PH_ORVERFLO "arg int overflow !\n"
# define PH_MUTALLOC "pthread_mutex_init alloc fail !\n"

# define PH_FORK "has taken a fork"
# define PH_EAT "is eating"
# define PH_SLEEP "is sleeping"
# define PH_THINK "is thinking"
# define PH_DEATH "died"

typedef struct s_data	t_data;

typedef struct s_philo
{
	pthread_t			thread;
	pthread_mutex_t		fork;
	long				death_date;
	int					nb_eat;
	int					num;
	pthread_mutex_t		*next;
	t_data				*data;
	struct timeval		time;
	int					time_eat;
	int					time_die;
	int					time_sleep;
	int					nb_must_eat;
}				t_philo;

typedef struct s_data
{
	t_philo			*table;
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_must_eat;
	int				philo_die;
	int				philo_error;
	pthread_mutex_t	data_rw;
	pthread_mutex_t	print_stdout;
}				t_data;

void	philo_exit(int error, char *msg, t_data *data);

#endif /* PHILO_H */
