/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 13:18:59 by akant         #+#    #+#                 */
/*   Updated: 2021/12/16 16:46:03 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		data_init(t_data *data, int argc, char **argv)
{
	data->number_of_philosophers = ft_atoi(argv[1]);
	if (atoi_failed(argv[1], data->number_of_philosophers))
		return (1);
	data->time_to_die = ft_atoi(argv[2]);
	if (atoi_failed(argv[2], data->time_to_die))
		return (1);
	data->time_to_eat = ft_atoi(argv[3]);
	if (atoi_failed(argv[3], data->time_to_eat))
		return (1);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (atoi_failed(argv[4], data->time_to_sleep))
		return (1);
	if (argc == 6)
	{
		data->amount_each_must_eat = ft_atoi(argv[5]);
		if (atoi_failed(argv[5], data->amount_each_must_eat))
			return (1);
	}
	else
		data->amount_each_must_eat = -1;
	return (0);
}

int		input_checking(t_data data, int argc)
{
	if (data.number_of_philosophers < 0
		|| data.time_to_die <= 0 || data.time_to_eat <= 0
		|| data.time_to_sleep <= 0)
		return (1);
	if (argc == 6 && data.amount_each_must_eat <= 0)
		return (1);
	return (0);
}
