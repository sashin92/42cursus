/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:17:43 by sashin            #+#    #+#             */
/*   Updated: 2021/12/01 14:40:54 by sashin           ###   ########.fr       */
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

void	thread_monitor(t_philo *philos)
{
	int		i;
	int		j;

	i = 0;
	printf("this %lld\n", ft_get_time() - philos[i].time);
	while (1)
	{
		if (ft_get_time() - philos[i].time >= philos[i].info->time_to_die)
		{
			pthread_mutex_lock(&philos[i].info->mutex_print);
			philos[i].info->isdied = 1;
			change_status(&philos[i], DIED);
			printf("%lld\t%d died\n",ft_get_time() - philos[i].info->start_time, philos[i].num);
			pthread_mutex_unlock(&philos[i].info->mutex_print);
			break ;
		}
		else if (philos->info->ismin == 1 && check_isfinished(philos))
			break ;
		++i;
		i = i % philos->info->number_of_philosophers;
	}
	pthread_mutex_destroy(&philos[i].info->mutex_print);
	pthread_mutex_destroy(&philos[i].info->mutex_status);
	j = 0;
	while (j < philos[i].info->number_of_philosophers)
		pthread_mutex_destroy(&philos[i].info->mutex_fork[j++]);
	// free(philos);
	// free(philos[i].info->mutex_fork);
}

void	*thread_main(void *philo_void)
{
	t_philo		*philo;
	int			i;

	i = 0;
	philo = (t_philo *)philo_void;
	if (philo->info->ismin == 1 && \
		philo->info->number_of_times_each_philosopher_must_eat == 0)
		return (NULL);
	while (!philo->info->isdied)
	{
		action_eating(philo);
		action_sleeping(philo);
	}
	return (NULL);
}
