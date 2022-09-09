/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:01:22 by mahadad           #+#    #+#             */
/*   Updated: 2022/09/09 15:22:00 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "ph_debug.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief Create link list for all philo.
 */
static void	philo_data_constructor(int nb, t_data *data)
{
	t_philo	*tmp;

	nb++;//NOTE if the code arrived here `nb` need to not be `0`.
	data->table = malloc(sizeof(t_philo));
	if (!data->table)
		philo_exit(EXIT_FAILURE, "t_philo alloc fail.", data);
	tmp = data->table;
	while (nb != 0)
	{
		tmp->next = malloc(sizeof(t_philo));
		if (!tmp->next)
			philo_exit(EXIT_FAILURE, "t_philo alloc fail.", data);
		nb--;
	}
}

/**
 * @brief Will set all the memory block of a struct to `0` bit.
 * 
 * @param data 
 */
static void	struct_to_null(void *data, int size)
{
	memset((char *)data, 0, size);
}

int	ft_isdigit(int c);

/**
 * @brief Check if all input are positif number, if not will exit with a error
 *        message.
 */
static void	arg_check(int ac, char **av, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < ac)
	{
		while (av[x][y])
		{
			if (!ft_isdigit(av[x][y]))
				philo_exit(EXIT_FAILURE, "non digit character or "
					"negative number in arg.\n", data);
			y++;
		}
		y = 0;
		x++;
	}
}

static void	set_data(int ac, char **av, t_data *data)
{
	struct_to_null(data, sizeof(t_data));
	data->nb_philo = ft_atoi(av[0]);
	data->time_die = ft_atoi(av[1]);
	data->time_eat = ft_atoi(av[2]);
	data->time_sleep = ft_atoi(av[3]);
	if (ac == 5)
		data->nb_must_eat = ft_atoi(av[4]);
	//TODO make behaviour for the `0` case
	if (PH_DEBUG)
	{
		printf("nb_philo    [%d]\ntime_die    [%d]\n"
			"time_sleep  [%d]\nnb_must_eat [%d]\n",
			data->nb_philo, data->time_die, data->time_sleep,
			data->nb_must_eat);
	}
}

int	ft_atoi(const char *str);

/**
 * @brief Will skip the first `ac` and `av` arg. Check if the args are only
 *        digit character and populate the data struct.
 */
void	arg_init(int ac, char **av, t_data *data)
{
	ac--;
	av++;
	if (!(ac == 4 || ac == 5))
		philo_exit(EXIT_FAILURE, PH_BADARG1 PH_BADARG2, data);
	arg_check(ac, av, data);

	philo_data_constructor(ac, data);
}