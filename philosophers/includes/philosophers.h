/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:26:45 by sashin            #+#    #+#             */
/*   Updated: 2021/11/27 18:19:43 by sashin           ###   ########.fr       */
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

// typedef enum	t_error
// {
// 	ERROR = -1,

// }

typedef enum	e_status
{
	THINKING,
	EATING,
	SLEEPING,
	DIED,
}				t_status;

typedef struct	s_info
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	long long		start_time;
	int				err_flag;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
}					t_info;

typedef struct	s_philo
{
	pthread_t		thread;
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
int			ft_relative_time(struct timeval t1, struct timeval t2);
long long	ft_get_time(void);

/*
** error.c
*/
int			error_msg(int err_flag);

/*
** thread.c
*/
void		*thread_main(void *philo);

/*
** action.c
*/
void		action_eating(t_philo *philo);
void		action_sleeping(t_philo *philo);


#endif