/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   die.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 16:05:34 by akant         #+#    #+#                 */
/*   Updated: 2021/12/16 14:06:46 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosopher_died(int name, long long usec)
{
	printf("%*lld %d died\n", 5, usec, name);
	return (0);
}

int	die_in_sleep(t_args *args)
{
	args->current_time = time_in_us();
	if (args->current_time + args->data->time_to_sleep * 1000
		> args->last_eat_time + args->data->time_to_die * 1000)
	{
		usleep(args->last_eat_time + args->data->time_to_die * 1000 - args->current_time);
		args->current_time = time_in_us();
		// if (args->data->philo_that_is_done)
		// 	return (0);
		args->data->philo_that_is_done = args->name;
		return (philosopher_died(args->name, (args->current_time - args->data->start_time) / 1000));
	}
	return (0);
}
