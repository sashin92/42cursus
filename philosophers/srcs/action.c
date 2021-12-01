/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:16:44 by sashin            #+#    #+#             */
/*   Updated: 2021/11/30 15:40:32 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_mutex_print(t_philo *philo, char *str, int time, int i)
{
	if (!philo->info->isdead)
	{
		pthread_mutex_lock(&philo->info->mutex_print);
		if (i == -1)
			printf("%d\t%s\n", time, str);
		else
			printf("%d\t%d %s\n", time, i, str);
		pthread_mutex_unlock(&philo->info->mutex_print);
	}
}

void	action_sleeping(t_philo *philo)
{
	long long	now;

	now = ft_get_time();
	ft_mutex_print(philo, "is sleeping", \
			now - philo->info->start_time, philo->num);
	philo->eat_count++;
	while (ft_get_time() - now < philo->info->time_to_sleep)
		usleep(100);
}

void	action_eating(t_philo *philo)
{
	long long	now;

	if (philo->num % 2)
		pthread_mutex_lock(&philo->info->mutex_fork[philo->fork_l]);
	else
		pthread_mutex_lock(&philo->info->mutex_fork[philo->fork_r]);
	ft_mutex_print(philo, "has taken a fork", \
					ft_get_time() - philo->info->start_time, philo->num);
	if (philo->num % 2)
		pthread_mutex_lock(&philo->info->mutex_fork[philo->fork_r]);
	else
		pthread_mutex_lock(&philo->info->mutex_fork[philo->fork_l]);
	now = ft_get_time();
	philo->time = ft_get_time();
	ft_mutex_print(philo, "is eating", now - philo->info->start_time, \
					philo->num);
	while (ft_get_time() - now < philo->info->time_to_eat)
		usleep(100);
	pthread_mutex_unlock(&philo->info->mutex_fork[philo->fork_l]);
	pthread_mutex_unlock(&philo->info->mutex_fork[philo->fork_r]);
}
