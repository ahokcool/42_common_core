/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:03:26 by astein            #+#    #+#             */
/*   Updated: 2023/08/05 05:01:02 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
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
}							t_bool;

typedef struct s_philo
{
	int						number;
	//Each philosopher has a number ranging from 1 to number_of_philosophers.
	pthread_t				tid;
	pthread_mutex_t			m_philo;
	int						state;
	long					duration_die;
	long					duration_eat;
	long					duration_sleep;
	struct timeval			t_last_meal;
	t_bool					has_left_fork;
	t_bool					has_right_fork;
	struct s_philo			*left_philo;
	struct s_philo			*right_philo;
	int						count_meals;
	// from dining table
	// t_bool			*dinner_started;
	// struct timeval	*t_start;
	// pthread_mutex_t	*m_print;
	struct s_dining_table	*dining_table;

}							t_philo;

typedef struct s_dining_table
{
	t_bool					dinner_started;
	pthread_mutex_t			m_dinner_started;
	t_bool					dinner_over;
	pthread_mutex_t			m_dinner_over;
	int						num_philos;
	long					duration_die;
	long					duration_eat;
	long					duration_sleep;
	struct timeval			t_start;
	struct timeval			t_curr;
	int						times_each_philo_must_eat;
	pthread_mutex_t			m_print;
	int						amount_of_phillos_done_eating;
	t_philo					*philos;
}							t_dining_table;

//UTILS
long						ft_atol(char *a);
void						print_msg(t_philo *philo, char *msg);
void						free_philo(t_philo *philo);

//PHILOS
void						ini_philos(t_dining_table *dining_table);
void						join_philos(t_dining_table *dining_table);
t_bool						check_if_any_philo_died(t_dining_table *dining_table);
t_bool						check_if_all_philo_have_eaten_enough(t_dining_table *dining_table);
void						free_philos(t_dining_table *dining_table);

//PHILO
void						*life_of_philo(void *arg);

//DINNING TABLE
t_bool						dinning_started(t_dining_table *dining_table);
t_bool						dinner_over(t_dining_table *dining_table);
void						free_dining_table(t_dining_table *dining_table);

void	ini_dining_table(t_dining_table *dining_table,
						int argc,
						char **argv);
void						check_times_gt_zero(t_dining_table *dining_table);
void						check_philos_gt_zero(t_dining_table *dining_table);
void						check_each_philo_must_eat(t_dining_table *dining_table);

#endif
