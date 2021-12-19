/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 10:58:48 by akant         #+#    #+#                 */
/*   Updated: 2021/12/16 14:05:48 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

// # include <unistd.h>
// # include <sys/types.h>
// # include "libft/libft.h"
// # include <sys/stat.h>
// # include <fcntl.h>
// # include <stdio.h>
// # include <readline/history.h>
// # include <readline/readline.h>

typedef struct s_data
{
	int	philo_that_is_done;
	int	died;
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	amount_each_must_eat;
	int	*amount_philos_not_full_yet;
	pthread_mutex_t	*lock_permission;
	pthread_mutex_t	*lock_amount_not_full_yet;
	pthread_mutex_t	*locks;
	long long	start_time;
}		t_data;

typedef struct s_args
{
	int				name;

	t_data			*data;
	long long	last_eat_time;
	long long	current_time;
	int			times_eaten;
}					t_args;

// Die.c
int		philosopher_died(int name, long long usec);
int		die_in_sleep(t_args *args);

// Eat.c
int		philo_eat(t_args *args);

// Ft_atoi.c
int		atoi_failed(char *str, int x);
int		ft_atoi(const char *str);

// Init.c
int		data_init(t_data *data, int argc, char **argv);
int		input_checking(t_data data, int argc);

// Lock1.c
int	init_forks(t_data *data, pthread_mutex_t *locks);
pthread_mutex_t *lock1_calc(t_args *args);
pthread_mutex_t *lock2_calc(t_args *args);

// Main.c
void	permission(t_args *args);
int		is_everyone_done(t_args *args);
int		main(int argc, char **argv);

// Sleep
void	smart_sleep(long long time);
int		philo_sleep(t_args *args);

// Time
long long	time_to_ms(struct timeval time);
long long	time_in_ms(void); // t_args *args);
long long	time_in_us(void); // temporary

// New file still to make
void	has_eaten_enough(t_args *args);
#endif
