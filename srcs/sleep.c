/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sleep.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 15:54:14 by akant         #+#    #+#                 */
/*   Updated: 2021/12/16 14:10:58 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	smart_sleep(long long time)
{
	int	start;
	int	current;

	start = time_in_us();
	current = start;
	while (current - start < time)
	{
		usleep(50);
		current = time_in_us();
	}
}

int	philo_sleep(t_args *args)
{
	permission(args);
	printf("%*lld %d started sleeping\n", 5,
		(args->last_eat_time - args->data->start_time) / 1000, args->name);
	if (die_in_sleep(args))
		return (1); // wat betekent return?
	smart_sleep(args->data->time_to_sleep * 1000);
	args->current_time = time_in_us();
	if ((args->current_time - args->last_eat_time) / 1000 > args->data->time_to_die)
	{
		permission(args);
		args->data->philo_that_is_done = args->name;
		return (philosopher_died(args->name,
			(args->current_time - args->data->start_time) / 1000));
	}
	return (-1);
}
