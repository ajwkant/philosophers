/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/05 15:36:48 by akant         #+#    #+#                 */
/*   Updated: 2021/12/14 12:09:46 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	time_to_ms(struct timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long long	time_in_ms(void) // t_args *args)
{
	struct timeval time;

	if(gettimeofday(&time, NULL))
		return (0);
	return (time_to_ms(time));
}

long long	time_to_us(struct timeval time) // temp
{
	return (time.tv_sec * 1000000 + time.tv_usec);
}

long long	time_in_us(void) // temp
{
	struct timeval time;

	if(gettimeofday(&time, NULL))
		return (0);
	return (time_to_us(time));
}
