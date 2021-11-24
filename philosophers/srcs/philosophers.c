/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:26:29 by sashin            #+#    #+#             */
/*   Updated: 2021/11/24 16:37:38 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


		// pthread_create(new[idx].thread, NULL, &thread_main, NULL);



int		philo_free_mutex_destroy(t_philo **new, int idx)
{
	int		i;
	int		ret;
	int		flag;

	i = 0;
	flag = 0;
	while (i < idx)
	{
		ret = pthread_mutex_destroy(&new[i]->mutex);
		if (ret != 0)
			flag = -4;
		++i;
	}
	free(*new);
	*new = NULL;
	if (flag == -4)
		return (-4);
	return (-3);
}


void		action_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	
	philo->fork_l = 0;
	printf("x, %d has taken a fork L\n", philo->i);
	philo->fork_r = 0;
	printf("x, %d has taken a fork R\n", philo->i);

	pthread_mutex_unlock(&philo->mutex);
}

// void		action_eating(t_philo *philo)
// {
	
// }


void		*thread_main(void *philo)
{
	// if 포크가 두개 다 있다면 먹는다. 먹고나면 잔다. 자고 일어나면 생각한다(대기상태)
	// if 쓸 수 있는 포크가 없으면 생각한다(대기상태). 일정 시간이 지나면 죽는다.
	// if 스탠바이 된 상태라면
	action_take_fork(philo);
	// action_eating(philo);
	// action_put_fork(philo);
	// action_sleeping(philo);
	// action_thinking(philo);
	return (NULL);
}

// 포크가 공유된상태여야한다. 공유데이터 -> heap or data.

int		generate_philo(t_info *info, t_philo **philo)
{
	t_philo	*new;
	int		idx;
	int		flag;

	flag = 0;
	new = (t_philo *)malloc(sizeof(t_philo) * info->number_of_philosophers);
	if (new == NULL)
		flag = -2;
	idx = 0;
	while (flag == 0 && idx < info->number_of_philosophers)
	{
		new[idx].i = idx + 1;
		new[idx].fork_l = idx + 1;
		new[idx].fork_r = (idx + 1) % (info->number_of_philosophers) + 1;
		new[idx].eat_count = 0;
		new[idx].status = THINKING;
		new[idx].info = info;
		flag = pthread_mutex_init(&new[idx].mutex, NULL);
		if (flag != 0)
			flag = philo_free_mutex_destroy(&new, idx);
		idx++;
	}
	*philo = new;
	return (flag);
}

void		run(t_info *info)
{
	int		i;
	t_philo	*philo;

	info->err_flag =  generate_philo(info, &philo);
	if (info->err_flag != 0)
		return ;
	i = 0;
	while (i < info->number_of_philosophers)
	{
		printf("fork L: %d, R: %d\n", philo[i].fork_l, philo[i].fork_r);
		pthread_create(&philo[i].thread, NULL, thread_main, &philo[i]);
		pthread_join(philo[i].thread, NULL);
		printf("fork L: %d, R: %d\n\n", philo[i].fork_l, philo[i].fork_r);
		++i;
	}
}

void		check_parse(t_info *info, int argc, char **argv)
{
	info->err_flag = 0;
	info->number_of_philosophers = ft_atoi_nosign(argv[1]);
	info->time_to_die = ft_atoi_nosign(argv[2]);
	info->time_to_eat = ft_atoi_nosign(argv[3]);
	info->time_to_sleep = ft_atoi_nosign(argv[4]);
	if (info->number_of_philosophers == -1 || info->time_to_die == -1 || \
		info->time_to_eat == -1 || info->time_to_sleep == -1)
		info->err_flag = -1;
	if (argc == 6)
	{
		info->number_of_times_each_philosopher_must_eat = ft_atoi_nosign(argv[5]);
		if (info->number_of_times_each_philosopher_must_eat == -1)
			info->err_flag = -1;
	}
	else
		info->number_of_times_each_philosopher_must_eat = 0;
}



int		main(int argc, char **argv)
{
	t_info	info;

	if (argc == 5 || argc == 6)
	{
		check_parse(&info, argc, argv);
		if (info.err_flag == 0)
			run(&info);
		if (info.err_flag < 0)
			error_msg(info.err_flag);
	}
	else
		printf("Please Input valid data.\n");
	return (0);
}



////////////////////////// 예제코드

// int		main(int argc, char **argv)
// {
// 	(void)argc;
// 	int a = ft_atoi_nosign(argv[1]);
// 	printf("this is %d\n", a);
// 	return 0;
// }
