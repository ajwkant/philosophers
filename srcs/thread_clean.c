/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thread_clean.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 10:28:03 by akant         #+#    #+#                 */
/*   Updated: 2021/12/17 10:55:56 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_clean()
{
	void *status;

	pthread_join(monitor, &status);
	mutex_destroy
	pthread_join(thread_id[data.philo_that_is_done - 1], &status);
	while (i <= data.number_of_philosophers)
	{
		if (i != data.philo_that_is_done)
			pthread_detach(thread_id[i - 1]);
		i++;
	}
}
