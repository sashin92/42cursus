/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:17:43 by sashin            #+#    #+#             */
/*   Updated: 2021/12/02 20:07:02 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	change_status_print(t_philo *philo, t_status cur, int i)
{
	long long	timestamp;

	timestamp = 0;
	pthread_mutex_lock(&philo->info->mutex_print);
	timestamp = ft_get_time() - philo->info->start_time;
	philo->status = cur;
	if (!philo->info->isfinish)
	{
		if (cur == TAKE_FORK)
			printf("%lld\t%d has taken a fork\n", timestamp, i);
		else if (cur == EATING)
		{
			philo->time = ft_get_time();
			printf("%lld\t%d is eating\n", timestamp, i);
		}
		else if (cur == SLEEPING)
			printf("%lld\t%d is sleeping\n", timestamp, i);
		else if (cur == THINKING)
			printf("%lld\t%d is thinking\n", timestamp, i);
	}
	pthread_mutex_unlock(&philo->info->mutex_print);
}

static void	action_sleeping(t_philo *philo)
{
	long long	now;
	int			time_to_sleep;
	int			must_eat;

	time_to_sleep = philo->info->time_to_sleep;
	now = ft_get_time();
	must_eat = philo->info->number_of_times_each_philosopher_must_eat;
	if (philo->info->isfinish != 1)
		change_status_print(philo, SLEEPING, philo->num);
	philo->eat_count++;
	if (philo->eat_count == must_eat)
	{
		pthread_mutex_lock(&philo->info->mutex_count);
		philo->info->end_count++;
		pthread_mutex_unlock(&philo->info->mutex_count);
	}
	while (ft_get_time() - now < philo->info->time_to_sleep)
		usleep(100);
	if (philo->info->isfinish != 1)
		change_status_print(philo, THINKING, philo->num);
}

static void	action_eating(t_philo *philo)
{
	long long	now;
	int			time_to_eat;

	time_to_eat = philo->info->time_to_eat;
	if (philo->num % 2)
		pthread_mutex_lock(&philo->info->mutex_fork[philo->fork_l]);
	else if (!(philo->num % 2))
		pthread_mutex_lock(&philo->info->mutex_fork[philo->fork_r]);
	if (philo->info->isfinish != 1)
		change_status_print(philo, TAKE_FORK, philo->num);
	if (philo->num % 2)
		pthread_mutex_lock(&philo->info->mutex_fork[philo->fork_r]);
	else if (!(philo->num % 2))
		pthread_mutex_lock(&philo->info->mutex_fork[philo->fork_l]);
	if (philo->info->isfinish != 1)
		change_status_print(philo, EATING, philo->num);
	now = ft_get_time();
	while (ft_get_time() - now < time_to_eat)
		usleep(100);
	pthread_mutex_unlock(&philo->info->mutex_fork[philo->fork_l]);
	pthread_mutex_unlock(&philo->info->mutex_fork[philo->fork_r]);
}

static void	plus_count(t_philo *philo, int flag)
{
	pthread_mutex_lock(&philo->info->mutex_count);
	philo->info->thread_count++;
	if (flag == 1)
		philo->info->end_count++;
	pthread_mutex_unlock(&philo->info->mutex_count);
}

void	*thread_function(void *philo_void)
{
	t_philo		*philo;
	int			i;

	i = 0;
	philo = (t_philo *)philo_void;
	if (philo->info->ismin == 1 && \
		philo->info->number_of_times_each_philosopher_must_eat == 0)
		plus_count(philo, 1);
	else if (philo->info->number_of_philosophers == 1)
		plus_count(philo, 0);
	else
	{
		while (!philo->info->isfinish)
		{
			action_eating(philo);
			action_sleeping(philo);
		}
		plus_count(philo, 0);
	}
	return (NULL);
}
