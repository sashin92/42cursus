/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:16:44 by sashin            #+#    #+#             */
/*   Updated: 2021/11/27 18:19:59 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void		ft_mutex_print(pthread_mutex_t *mutex, char *str, int time, int i)
{
	pthread_mutex_lock(mutex);
	printf("%dms %d %s\n", time, i, str);
	pthread_mutex_unlock(mutex);
}

void		action_sleeping(t_philo *philo)
{
	long long	t1;
	long long	t2;
	
	if (philo->status == SLEEPING)
	{
		t1 = ft_get_time();
		t2 = ft_get_time();
		ft_mutex_print(&philo->info->print, "is sleeping", t1 - philo->info->start_time, philo->num);
		while (t2 - t1 < philo->info->time_to_sleep)
		{
			t2 = ft_get_time();
			usleep(100);
		}
		philo->status = THINKING;
		ft_mutex_print(&philo->info->print, "is thinking", t2 - philo->info->start_time, philo->num);
	}
}

void		action_eating(t_philo *philo)
{
	long long	t2;

	while (philo->status == THINKING)
	{
		philo->time = ft_get_time();
		if ((philo->num % 2 && !pthread_mutex_lock(&philo->info->fork[philo->fork_l])) || \
			(!((philo->num) % 2) && !pthread_mutex_lock(&philo->info->fork[philo->fork_r])))
		{
			philo->time = ft_get_time();
			ft_mutex_print(&philo->info->print, "has taken a fork", philo->time - philo->info->start_time, philo->num);
			while (philo->status == THINKING)
			{
				if ((philo->num % 2 && !pthread_mutex_lock(&philo->info->fork[philo->fork_r])) || \
					(!((philo->num) % 2) && !pthread_mutex_lock(&philo->info->fork[philo->fork_l])))
				{
					t2 = ft_get_time();
					philo->status = EATING;
					// ft_mutex_print(&philo->info->print, "has taken a fork L", t2 - philo->info->start_time, philo->i);
					ft_mutex_print(&philo->info->print, "is eating", t2 - philo->info->start_time, philo->num);
					while (ft_get_time() - t2 < philo->info->time_to_eat)
					{
						// philo->time = ft_get_time();
						usleep(100);
					}
					pthread_mutex_unlock(&philo->info->fork[philo->fork_l]);
					pthread_mutex_unlock(&philo->info->fork[philo->fork_r]);
					philo->status = SLEEPING;
					break ;
				}
			}
		}
	}
}
