/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:03:26 by astein            #+#    #+#             */
/*   Updated: 2023/08/01 23:10:17 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define MSG_FORK " has taken a fork"
# define MSG_EAT " is eating"
# define MSG_SLEEP " is sleeping"
# define MSG_THINK " is thinking"
# define MSG_DIED " died"

# define EATING 0
# define SLEEPING 1
# define THINKING 2
# define DIED -1

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

typedef struct s_dining_table
{
	int		num_philos;
	long	time_die;
	long	time_eat;
	long	time_sleep;
	int		times_each_philo_must_eat;

}			t_dining_table;

typedef struct s_philo
{
	int		number;
	//Each philosopher has a number ranging from 1 to number_of_philosophers.
}			t_philo;

void		ft_putstr(char *s);
void		ini_dining_table(t_dining_table *dining_table, int argc,
				char **argv);
void		init_philos(t_dining_table *dining_table);
long		ft_atol(char *a);
void		check_times_gt_zero(t_dining_table *dining_table);
void		check_philos_gt_zero(t_dining_table *dining_table);
void	check_each_philo_must_eat(t_dining_table *dining_table);

#endif
