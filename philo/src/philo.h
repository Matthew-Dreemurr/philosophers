/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:21:37 by mahadad           #+#    #+#             */
/*   Updated: 2022/10/10 11:54:02 by mahadad          ###   ########.fr       */
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

# define PH_DEATH_EXIT 5
# define PH_EAT_EXIT 4

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
	int					time_eat;
	int					time_die;
	int					time_sleep;
	long				start_date;
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
	int				nb_eat;
	int				philo_die;
	pthread_mutex_t	data_rw;
}				t_data;

void	ph_exit_msg(int error, const char *msg);
void	philo_free(t_data *data);
long	gettime(void);
int		set_death_date(t_philo *me);
int		is_death(t_philo *me, long override);
int		ph_print(char *msg, t_philo *me, long override);
int		msleep(int ms, t_philo *me, int check_death);

#endif /* PHILO_H */
