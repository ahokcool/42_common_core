/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:03:26 by astein            #+#    #+#             */
/*   Updated: 2023/08/05 00:08:13 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
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
}					t_bool;

typedef struct s_philo
{
	int				number;
	//Each philosopher has a number ranging from 1 to number_of_philosophers.
	int			state;
	pthread_mutex_t	m_state;
	struct timeval	t_last_meal;
	t_bool			has_left_fork;
	t_bool			has_right_fork;
	struct s_philo	*left_philo;
	struct s_philo	*right_philo;
	int				count_meals;
	pthread_mutex_t	*m_print;
}					t_philo;

typedef struct s_dining_table
{
	int				num_philos;
	long			duration_die;
	long			duration_eat;
	long			duration_sleep;
	struct timeval	t_start;
	struct timeval	t_curr;
	int				times_each_philo_must_eat;
	pthread_mutex_t	m_print;
	int				amount_of_phillos_done_eating;
	t_philo			*philos;
}					t_dining_table;

//UTILS
long				ft_atol(char *a);
void				print_msg(t_philo *philo, char *msg);

//PHILOS


void				ini_dining_table(t_dining_table *dining_table, int argc,
						char **argv);
void				init_philos(t_dining_table *dining_table);
void				check_times_gt_zero(t_dining_table *dining_table);
void				check_philos_gt_zero(t_dining_table *dining_table);
void				check_each_philo_must_eat(t_dining_table *dining_table);

#endif
