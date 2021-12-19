/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lock.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 15:48:11 by akant         #+#    #+#                 */
/*   Updated: 2021/12/17 10:30:43 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_data *data, pthread_mutex_t *locks)
{
	int i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&(locks[i]), NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

pthread_mutex_t *lock1_calc(t_args *args)
{
	pthread_mutex_t	*lock1;

	lock1 = args->data->locks + args->name - 1;
	if (args->name % 2 == 0)
		lock1 = args->data->locks + args->name % args->data->number_of_philosophers;
	return (lock1);
}

pthread_mutex_t *lock2_calc(t_args *args)
{
	pthread_mutex_t	*lock2;

	lock2 = args->data->locks + args->name % args->data->number_of_philosophers;
	if (args->name % 2 == 0)
		lock2 = args->data->locks + args->name - 1;
	return (lock2);
}

int	mutex_destoy_forks(pthread_mutex_t *locks)
{

}

int	mutex_destoy_lock(pthread_mutex_t *lock)
{

}

