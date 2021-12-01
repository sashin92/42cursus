/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:17:43 by sashin            #+#    #+#             */
/*   Updated: 2021/11/30 15:35:56 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_isfinished(t_philo *philo)
{
	int		i;

	i = 0;
	if (philo->info->number_of_times_each_philosopher_must_eat > 0)
	{
		while (i < philo->info->number_of_philosophers)
		{
			if (philo[i].eat_count >= philo[i].info->number_of_times_each_philosopher_must_eat)
				++i;
			else
				return (0);
		}
	}
	return (1);
}

void	*thread_monitor(void *philo_void)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)philo_void;
	i = 0;
	while (1)
	{
		if (ft_get_time() - philo[i].time > philo[i].info->time_to_die)
		{
			pthread_mutex_lock(&philo->info->mutex_print);
			printf("%lld\t%d died\n", ft_get_time() - philo[i].info->start_time, philo[i].num);
			usleep(100);
			// ft_mutex_print(philo, "died", \
			// 		ft_get_time() - philo[i].info->start_time, philo[i].num);
			break ;
		}
		if (philo->info->ismin == 1 && check_isfinished(philo))
			break ;
		++i;
		i = i % philo->info->number_of_philosophers;
	}
	pthread_mutex_destroy(&philo->info->mutex_print);
	pthread_mutex_destroy(&philo->info->mutex_dead);
	i = 0;
	while (i < philo->info->number_of_philosophers)
		pthread_mutex_destroy(&philo->info->mutex_fork[i++]);
	free(philo);
	return (NULL);
}

void	*thread_main(void *philo_void)
{
	t_philo		*philo;
	int			i;

	i = 0;
	philo = (t_philo *)philo_void;
	philo->time = ft_get_time();
	if (philo->info->ismin == 1 && philo->info->number_of_times_each_philosopher_must_eat == 0)
		return (NULL);
	while (1)
	{
		action_eating(philo);
		action_sleeping(philo);
		usleep(1000);
	}
	return (NULL);
}
