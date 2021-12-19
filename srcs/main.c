/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 11:00:22 by akant         #+#    #+#                 */
/*   Updated: 2021/12/17 12:58:08 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Remove exit function
// Check return van time in ms
// What happens with only 1 philo? hardcode this
// Destroy mutexes

#include "philo.h"

void	permission(t_args *args)
{
	pthread_mutex_lock(args->data->lock_permission);
	pthread_mutex_unlock(args->data->lock_permission);
}

int		is_everyone_done(t_args *args)
{
	int ret;

	ret = 0;
	if (*(args->data->amount_philos_not_full_yet) == 0)
	{
		pthread_mutex_lock(args->data->lock_permission);
		ret = 1;
		args->data->philo_that_is_done = args->name;
		pthread_mutex_unlock(lock1_calc(args));
		pthread_mutex_unlock(lock2_calc(args));

	}
	return (ret);
}

void	has_eaten_enough(t_args *args)
{
	pthread_mutex_lock(args->data->lock_amount_not_full_yet);
	(*(args->data->amount_philos_not_full_yet))--;
	pthread_mutex_unlock(args->data->lock_amount_not_full_yet);
}

int	eat_sleep_think_repeat(void *vargp)
{
	t_args		*args;
	int			ret;

	args = (t_args *)vargp;
	args->times_eaten = 0;
	args->last_eat_time = args->data->start_time;

	while (1)
	{
		ret = philo_eat(args);
		if (ret == 1 || ret == 0)
			return (ret);
		if (args->data->philo_that_is_done)
			return (0);
		ret = philo_sleep(args);
		if (ret == 1 || ret == 0)
			return (ret);
		if (args->data->philo_that_is_done)
			return (0);
		printf("%*lld %d started thinking\n", 5,
			(args->current_time - args->data->start_time) / 1000, args->name);
	}
	return (1);
}

int		create_philosophers(t_data data)
{
	int				i;
	int				amount_philos_not_full_yet;
	pthread_t		monitor;
	pthread_t		thread_id[data.number_of_philosophers];
	t_args			args[data.number_of_philosophers];
	pthread_mutex_t	locks[data.number_of_philosophers];
	pthread_mutex_t	lock_permission;
	pthread_mutex_t	lock_amount_not_full_yet;

	if (init_forks(&data, locks))
		return (1);

	if (pthread_mutex_init(&lock_permission, NULL) != 0)
		return (1);

	if (pthread_mutex_init(&lock_amount_not_full_yet, NULL) != 0)
		return (1);



	i = 1;
	amount_philos_not_full_yet = data.number_of_philosophers;
	data.philo_that_is_done = 0;
	data.died = 0;
	data.start_time = time_in_us();
	data.locks = locks;
	data.lock_permission = &lock_permission;
	data.lock_amount_not_full_yet = &lock_amount_not_full_yet;
	data.amount_philos_not_full_yet = &amount_philos_not_full_yet;

	pthread_create(&monitor, NULL, (void *)&monitor_run, (void *)&data);
	while (i <= data.number_of_philosophers)
	{
		args[i - 1].data = &data;
		args[i - 1].name = i;
		pthread_create(&(thread_id[i - 1]), NULL, (void *)&eat_sleep_think_repeat, (void *)(&(args[i - 1]))); // Check returnvalue
		i++;
	}
	i = 1;

	clean_threads();

	return (0);
}

int		main(int argc, char **argv)
{
	t_data data;

	if (!(argc == 5 || argc == 6))
		return (1);
	if (data_init(&data, argc, argv))
		return (1);
	if (input_checking(data, argc))
		return (1);
	return (create_philosophers(data));
}
