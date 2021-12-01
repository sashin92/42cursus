/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:16:44 by sashin            #+#    #+#             */
/*   Updated: 2021/12/01 14:03:49 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_mutex_print(t_philo *philo, t_status status, int i)
{
	long long	timestamp;

	timestamp = 0;
	pthread_mutex_lock(&philo->info->mutex_print);
	pthread_mutex_lock(&philo->info->mutex_status);
	timestamp = ft_get_time() - philo->info->start_time;
	if (status == TAKE_FORK)
		printf("%lld\t%d has taken a fork\n",timestamp, i);
	else if (status == EATING)
		printf("%lld\t%d is eating\n",timestamp, i);
	else if (status == SLEEPING)
		printf("%lld\t%d is sleeping\n",timestamp, i);
	else if (status == THINKING)
		printf("%lld\t%d is thinking\n",timestamp, i);
	pthread_mutex_unlock(&philo->info->mutex_print);
	pthread_mutex_unlock(&philo->info->mutex_status);
}

void	action_sleeping(t_philo *philo)
{
	long long	now;

	now = ft_get_time();
	change_status(philo, SLEEPING);
	if (!philo->info->isdied)
		ft_mutex_print(philo, philo->status, philo->num);
	philo->eat_count++;
	while (ft_get_time() - now < philo->info->time_to_sleep);
	change_status(philo, THINKING);
	if (!philo->info->isdied)
		ft_mutex_print(philo, philo->status, philo->num);
}

void	change_status(t_philo *philo, t_status cur)
{
	pthread_mutex_lock(&philo->info->mutex_status);
	if (philo->status != DIED)
		philo->status = cur;
	if (philo->status == EATING)
		philo->time = ft_get_time();
	pthread_mutex_unlock(&philo->info->mutex_status);
}

void	action_eating(t_philo *philo)
{
	long long	now;

	if (philo->num % 2)
		pthread_mutex_lock(&philo->info->mutex_fork[philo->fork_l]);
	else if (!(philo->num % 2))
		pthread_mutex_lock(&philo->info->mutex_fork[philo->fork_r]);
	change_status(philo, TAKE_FORK);
	if (!philo->info->isdied)
		ft_mutex_print(philo, philo->status, philo->num);
	if (philo->num % 2)
		pthread_mutex_lock(&philo->info->mutex_fork[philo->fork_r]);
	else if (!(philo->num % 2))
		pthread_mutex_lock(&philo->info->mutex_fork[philo->fork_l]);
	now = ft_get_time();
	change_status(philo, EATING);
	if (!philo->info->isdied)
		ft_mutex_print(philo, philo->status, philo->num);
	while (ft_get_time() - now < philo->info->time_to_eat);
	pthread_mutex_unlock(&philo->info->mutex_fork[philo->fork_l]);
	pthread_mutex_unlock(&philo->info->mutex_fork[philo->fork_r]);
}
