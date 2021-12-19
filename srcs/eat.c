/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eat.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 15:51:44 by akant         #+#    #+#                 */
/*   Updated: 2021/12/16 16:47:03 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_args *args)
{
	if (args->data->philo_that_is_done)
		return (0);
	pthread_mutex_lock(lock1_calc(args));
	if (args->data->philo_that_is_done)
		return (0);

	args->current_time = time_in_us();

	if ((args->current_time - args->last_eat_time) / 1000 > args->data->time_to_die)
	{
		args->data->philo_that_is_done = args->name;
		args->data->died = 1;
		return (philosopher_died(args->name, (args->current_time - args->data->start_time) / 1000));
	}

	permission(args);
	printf("%*lld %d has taken a fork\n", 5, (args->current_time - args->data->start_time) / 1000, args->name);
	pthread_mutex_lock(lock2_calc(args));

	args->current_time = time_in_us();
	if ((args->current_time - args->last_eat_time) / 1000 > args->data->time_to_die)
	{
		args->data->philo_that_is_done = args->name;
		return (philosopher_died(args->name, (args->current_time - args->data->start_time) / 1000));
	}

	permission(args);
	printf("%*lld %d has taken a fork\n", 5, (args->current_time - args->data->start_time) / 1000, args->name);
	printf("%*lld %d started eating\n", 5, (args->current_time - args->data->start_time) / 1000, args->name);

	smart_sleep(args->data->time_to_eat * 1000);
	args->times_eaten++;
	if (args->times_eaten == args->data->amount_each_must_eat)
	{
		has_eaten_enough(args);
		if (is_everyone_done(args))
			return (0);
	}
	// printf("Philo: %d, times eaten: %d\n", args->name, args->times_eaten);

	args->last_eat_time = time_in_us();
	pthread_mutex_unlock(lock1_calc(args));
	pthread_mutex_unlock(lock2_calc(args));
	// if (is_everyone_done(args))
	// 	return (0);
	return (-1);
}
