/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:16:44 by sashin            #+#    #+#             */
/*   Updated: 2021/12/02 18:40:51 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	die_process(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->mutex_print);
	philo->info->isfinish = 1;
	printf("%lld\t%d died\n", \
		ft_get_time() - philo->info->start_time, philo->num);
	pthread_mutex_unlock(&philo->info->mutex_print);
}

static void	finish_process(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->mutex_print);
	philo->info->isfinish = 2;
	printf("%lld\tFINISH\n", ft_get_time() - philo->info->start_time);
	pthread_mutex_unlock(&philo->info->mutex_print);
}

void	monitor(t_philo *philos)
{
	int		i;
	int		total;

	i = 0;
	total = philos[i].info->number_of_philosophers;
	while (1)
	{
		if (ft_get_time() - philos[i].time >= philos[i].info->time_to_die)
		{
			die_process(&philos[i]);
			break ;
		}
		else if (philos[i].info->ismin == 1 && \
					philos->info->end_count == total)
		{
			finish_process(&philos[i]);
			break ;
		}
		++i;
		i = i % total;
	}
	while (philos[i].info->thread_count != total)
		usleep(100);
}
