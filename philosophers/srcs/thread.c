/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:17:43 by sashin            #+#    #+#             */
/*   Updated: 2021/11/27 18:20:17 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


// void		action_take_forks(t_philo *philo)
// {
// 	if (philo->num % 2)
// 	{
// 		while (pthread_mutex_lock(&philo->info->fork[philo->fork_l]))
// 			usleep(100);
// 		while (pthread_mutex_lock(&philo->info->fork[philo->fork_r]))
// 			usleep(100);
// 	}
// 	else
// 	{
// 		while (pthread_mutex_lock(&philo->info->fork[philo->fork_r]))
// 			usleep(100);
// 		while (pthread_mutex_lock(&philo->info->fork[philo->fork_l]))
// 			usleep(100);
// 	}
// }

void		*thread_main(void *philo)
{
	long long	thinking_time;

	while (1)
	{
		thinking_time = ft_get_time();
		// action_take_forks(philo);
		action_eating(philo);
		action_sleeping(philo);
		usleep(100);
		
	}
	return (NULL);
}
