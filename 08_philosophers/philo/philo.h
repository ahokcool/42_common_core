/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:03:26 by astein            #+#    #+#             */
/*   Updated: 2023/08/10 02:16:05 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# ifndef PUT_MORE_INFOS
#  define PUT_MORE_INFOS 0
# endif

# define CLR_RED "\033[0;31m"
# define CLR_GREEN "\033[0;32m"
# define CLR_ORANGE "\033[0;33m"
# define CLR_BLUE "\033[0;34m"
# define CLR_MAGENTA "\033[0;35m"
# define CLR_CYAN "\033[0;36m"
# define CLR_RESET "\033[0m"
# define CLR_NONE ""

# define DIED -1
# define MSG_DIED -1

# define MSG_FORK_TAKE 0
# define MSG_FORK_DROP 1

# define EATING 2
# define MSG_EAT 2

# define FINISHED_EATING 3
# define MSG_EAT_END 3

# define SLEEPING 4
# define MSG_SLEEP 4

# define THINKING 5
# define MSG_THINK 5

# define MSG_ALL_EAT 6

# define NO_FORK -1

typedef enum e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct s_philo
{
	int				id;
	pthread_t		tid;
	pthread_mutex_t	m_philo;
	pthread_mutex_t	m_fork;
	int				state;
	struct timeval	t_last_meal;
	struct s_philo	*left_philo;
	struct s_philo	*right_philo;
	int				count_meals;
	struct s_table	*table;

}					t_philo;

typedef struct s_table
{
	pthread_mutex_t	m_started;
	pthread_mutex_t	m_ended;
	pthread_mutex_t	m_print;
	t_philo			*philos;
	t_bool			started;
	t_bool			ended;
	struct timeval	t_start;
	struct timeval	t_curr;
	int				num_philos;
	long			dur_die;
	long			dur_eat;
	long			dur_sleep;
	int				times_philo_must_eat;
	int				philos_done_eating;
	long			min_wait_time;
}					t_table;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// main
int					main(int argc, char **argv);
void				exit_dining(t_table *table, t_bool success);

//TABLE
void				ini_table(t_table *table, int argc, char **argv);
t_bool				has_started(t_table *table);
t_bool				has_ended(t_table *table);
void				set_dinner_start(t_table *table, t_bool has_started);
void				set_dinner_end(t_table *table, t_bool has_ended);

// CHECK
void				check_philos_gt_zero(t_table *table);
void				check_times_gt_zero(t_table *table);
void				check_each_philo_must_eat(t_table *table);
t_bool				check_if_alive(t_philo *philo);
t_bool				check_if_eaten_enough(t_philo *philo);

// PHILOS
void				ini_philos(t_table *table);
void				join_philos(t_table *table);
t_bool				check_if_any_philo_died(t_table *table);
t_bool				check_if_all_philo_have_eaten_enough(t_table *table);

// PHILO
int					get_state(t_philo *philo);
t_bool				set_state(t_philo *philo, int state);
int					get_meal_count(t_philo *philo);
int					get_meal_diff(t_philo *philo);
void				*life_of_philo(void *arg);

// PHILO ACTIONS
t_bool				start_eating(t_philo *philo);
t_bool				start_thinking(t_philo *philo);
t_bool				start_sleeping(t_philo *philo);

// FORKS.C
t_bool				request_for_forks(t_philo *philo);
void				drop_forks(t_philo *philo);

// MSG
void				put_msg_id(t_philo *philo, int msg_id, int fork);
void				put_extra_msg(pthread_mutex_t *m_print, char *msg,
						char *clr);
void				put_exit_msg(t_table *table, char *msg, t_bool success);

// MSG VALUES
const char			*get_msg(int msg_id);

// FREE
void				free_table(t_table *table);
void				free_philos(t_table *table);
void				free_philo(t_philo *philo);
void				*free_whatever(char *str, ...);

//Time
long int			get_time_diff_last_meal(t_philo *philo);
long int			get_time_diff(struct timeval *t1);

// LIB UTILS 1
long				ft_atol(char *a);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
size_t				ft_strlen(const char *s);
void				*ft_memcpy(void *dest, const void *src, size_t n);

// lst clear
void				null_ptr(void *nothing);
void				ft_lstclear(t_list **lst, void (*del)(void *));

// lst.c
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void *));

#endif
