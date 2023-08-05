/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:03:26 by astein            #+#    #+#             */
/*   Updated: 2023/08/05 20:22:37 by astein           ###   ########.fr       */
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

# ifndef PRINT_MORE_INFOS
#  define PRINT_MORE_INFOS = 0
# endif

# define MSG_FORK "has taken a fork"
# define MSG_EAT "is eating"
# define MSG_SLEEP "is sleeping"
# define MSG_THINK "is thinking"
# define MSG_DIED "died"

# define EATING 0
# define SLEEPING 1
# define THINKING 2
# define DIED -1

# define CLR_RED "\033[0;31m"
# define CLR_GREEN "\033[0;32m"
# define CLR_YELLOW "\033[0;33m"
# define CLR_BLUE "\033[0;34m"
# define CLR_MAGENTA "\033[0;35m"
# define CLR_CYAN "\033[0;36m"
# define CLR_ORANGE "\033[0;33m"
# define CLR_RESET "\033[0m"

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
	pthread_mutex_t			m_fork;
	int						state;
	long					duration_die;
	long					duration_eat;
	long					duration_sleep;
	struct timeval			t_last_meal;
	// t_bool					has_left_fork;
	// t_bool					has_right_fork;
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
	pthread_mutex_t			m_dinner_started;
	pthread_mutex_t			m_dinner_over;
	pthread_mutex_t			m_print;
	t_philo					*philos;
	t_bool					dinner_started;
	t_bool					dinner_over;
	struct timeval			t_start;
	struct timeval			t_curr;
	int						num_philos;
	long					duration_die;
	long					duration_eat;
	long					duration_sleep;
	int						times_each_philo_must_eat;
	int						amount_of_phillos_done_eating;
}							t_dining_table;

typedef struct s_list
{
	void					*content;
	struct s_list			*next;
}							t_list;

// LIB UTILS 1
long						ft_atol(char *a);
void						ft_bzero(void *s, size_t n);
void						*ft_calloc(size_t nmemb, size_t size);
size_t						ft_strlen(const char *s);
void						*ft_memcpy(void *dest, const void *src, size_t n);

// LIB UTILS 2
char						*ft_strcat_multi(int amount_of_strs, ...);

// LIB UTILS 3 - LST
t_list						*ft_lstnew(void *content);
void						ft_lstadd_front(t_list **lst, t_list *new);
void						ft_lstadd_back(t_list **lst, t_list *new);
t_list						*ft_lstlast(t_list *lst);
void						ft_lstdelone(t_list *lst, void (*del)(void *));

// free lst clear
void						null_ptr(void *nothing);
void						free_content(void *node);
void						ft_lstclear(t_list **lst, void (*del)(void *));

//UTILS
long int	get_time_diff(struct timeval *t_start,
						struct timeval *t_end);
void						print_msg(t_philo *philo, char *msg,
								t_dining_table *dining_table);
void						print_additional_msg(t_philo *philo, char *msg,
								t_dining_table *dining_table, char *clr);
// char						*ft_strjoin(char const *s1, char const *s2);

//PHILOS
void						ini_philos(t_dining_table *dining_table);
void						join_philos(t_dining_table *dining_table);
t_bool						check_if_any_philo_died(t_dining_table *dining_table);
t_bool						check_if_all_philo_have_eaten_enough(t_dining_table *dining_table);
void						free_philos(t_dining_table *dining_table);

//PHILO
void						*life_of_philo(void *arg);
void						free_philo(t_philo *philo);

//DINNING TABLE
void						set_dinner_start(t_dining_table *dining_table);
t_bool						dinning_started(t_dining_table *dining_table);
t_bool						is_dinner_over(t_dining_table *dining_table);
void						set_dinner_over(t_dining_table *dining_table);
void						free_dining_table(t_dining_table *dining_table);

// ft_free
void						*free_whatever(char *str, ...);

void	ini_dining_table(t_dining_table *dining_table,
						int argc,
						char **argv);
void						check_times_gt_zero(t_dining_table *dining_table);
void						check_philos_gt_zero(t_dining_table *dining_table);
void						check_each_philo_must_eat(t_dining_table *dining_table);

#endif
