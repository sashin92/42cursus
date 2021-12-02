/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:26:45 by sashin            #+#    #+#             */
/*   Updated: 2021/12/02 18:41:36 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

typedef enum e_status
{
	THINKING = 0,
	TAKE_FORK,
	EATING,
	SLEEPING,
	DIED,
}				t_status;

typedef struct s_info
{
	int				err_flag;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				ismin;
	int				isfinish;
	long long		start_time;
	int				end_count;
	int				thread_count;
	pthread_mutex_t	*mutex_fork;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_count;
}					t_info;

typedef struct s_philo
{
	int				num;
	int				fork_l;
	int				fork_r;
	int				eat_count;
	long long		time;
	t_status		status;
	t_info			*info;
}					t_philo;

/*
** utils.c
*/
int			ft_atou(char *str);
void		ft_putstr_fd(char *str, int fd);
void		*ft_memset(void *src, int c, size_t size);
long long	ft_get_time(void);
int			free_and_destroy(t_philo *philo, t_info *info);

/*
** error.c
*/
int			error_msg(int err_flag);

/*
** thread.c
*/
void		*thread_function(void *philo_void);

/*
** monitor.c
*/
void		monitor(t_philo *philo);

#endif