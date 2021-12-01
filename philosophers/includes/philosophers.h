/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:26:45 by sashin            #+#    #+#             */
/*   Updated: 2021/12/01 13:49:14 by sashin           ###   ########.fr       */
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
	THINKING,
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
	long long		start_time;
	int				isdied;
	pthread_mutex_t	*mutex_fork;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_status;
	pthread_mutex_t	mutex_process;
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
long long	ft_get_time(void);
void		*ft_memset(void *src, int c, size_t size);

/*
** error.c
*/
int			error_msg(int err_flag);

/*
** thread.c
*/
void		*thread_main(void *philo_void);
void		thread_monitor(t_philo *philo);

/*
** action.c
*/
void	change_status(t_philo *philo, t_status cur);
void		action_eating(t_philo *philo);
void		action_sleeping(t_philo *philo);
void		ft_mutex_print(t_philo *philo, t_status status, int i);

#endif