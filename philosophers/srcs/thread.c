/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:17:43 by sashin            #+#    #+#             */
/*   Updated: 2021/11/26 19:14:01 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void		*thread_main(void *philo)
{

	while (1)
	{
		action_eating(philo);
		action_sleeping(philo);
		// action_thinking(philo);
	}
	return (NULL);
}