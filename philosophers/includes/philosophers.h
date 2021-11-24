/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:26:45 by sashin            #+#    #+#             */
/*   Updated: 2021/11/24 17:13:34 by sashin           ###   ########.fr       */
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

# define THINKING 1
# define EATING 2
# define SLEEPING 3
# define DEAD 4

typedef struct	s_info
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				*fork;
	int				err_flag;
}					t_info;

typedef struct	s_philo
{
	pthread_t		thread;
	pthread_mutex_t	mutex;
	int				i;
	int				fork_l;
	int				fork_r;
	int				eat_count;
	int				status;
	t_info			*info;
}					t_philo;


/*
** utils.c
*/
int			ft_atoi_nosign(char *str);

/*
** error.c
*/
void		error_msg(int err_flag);

#endif