/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 10:26:31 by akant         #+#    #+#                 */
/*   Updated: 2021/12/17 10:55:52 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		monitor_run(t_data *data)
{
	while (data->philo_that_is_done == 0)
	{
		usleep(250);
	}
	mutex_destroy_forks();
	mutex_destroy_lock();

	mutex_destroy_lock();
	return (0);
}

// Tijdelijk eerst proberen alles te unlocken vanaf
// 1. Stop alle locks
// 2. Stop amount_not_full_yet
// 3.
