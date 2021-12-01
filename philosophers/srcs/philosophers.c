/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:26:29 by sashin            #+#    #+#             */
/*   Updated: 2021/12/01 13:54:10 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_free_mutex_destroy(t_philo **new, int idx)
{
	int		i;
	int		ret;
	int		flag;

	i = 0;
	flag = 0;
	while (i < idx)
	{
		ret = pthread_mutex_destroy(&new[i]->info->mutex_fork[i]);
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

static int	generate_philo(t_info *info, t_philo **philo)
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
		new[idx].num = idx + 1;
		new[idx].fork_l = idx;
		new[idx].fork_r = (idx + 1) % info->number_of_philosophers;
		new[idx].eat_count = 0;
		new[idx].info = info;
		new[idx].status = THINKING;
		flag = pthread_mutex_init(&new[idx].info->mutex_fork[idx], NULL);
		if (flag != 0)
			flag = philo_free_mutex_destroy(&new, idx);
		idx++;
	}
	*philo = new;
	return (flag);
}

static void	run(t_info *info)
{
	int			i;
	t_philo		*philo;
	pthread_t	thread;

	info->err_flag = generate_philo(info, &philo);
	if (info->err_flag != 0)
		return ;
	i = 0;
	info->start_time = ft_get_time();
	if (info->start_time < 0)
		info->err_flag = -5;
	while (info->err_flag == 0 && i < info->number_of_philosophers)
	{
		philo[i].time = ft_get_time();
		pthread_create(&thread, NULL, thread_main, &philo[i]);
		pthread_detach(thread);
		++i;
	}
	thread_monitor(philo);
	// pthread_detach(thread);
	// pthread_mutex_lock(&info->mutex_process);
	// while (1);
}

static void	check_parse(t_info *info, int argc, char **argv)
{
	info->number_of_philosophers = ft_atou(argv[1]);
	info->time_to_die = ft_atou(argv[2]);
	info->time_to_eat = ft_atou(argv[3]);
	info->time_to_sleep = ft_atou(argv[4]);
	if (info->number_of_philosophers == -1 || info->time_to_die == -1 || \
		info->time_to_eat == -1 || info->time_to_sleep == -1)
		info->err_flag = -1;
	if (argc == 6)
	{
		info->number_of_times_each_philosopher_must_eat = ft_atou(argv[5]);
		info->ismin = 1;
		if (info->number_of_times_each_philosopher_must_eat == -1)
			info->err_flag = -1;
	}
	if (info->err_flag == 0)
	{
		info->mutex_fork = malloc(sizeof(pthread_mutex_t) * \
						info->number_of_philosophers);
		if (info->mutex_fork == NULL)
			info->err_flag = -2;
		if (pthread_mutex_init(&info->mutex_status, NULL) && \
				pthread_mutex_init(&info->mutex_print, NULL) && \
				pthread_mutex_init(&info->mutex_process, NULL))
			info->err_flag = -3;
	}
	info->isdied = 0;
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc == 5 || argc == 6)
	{
		ft_memset(&info, 0, sizeof(t_info));
		check_parse(&info, argc, argv);
		if (info.err_flag == 0)
			run(&info);
		if (info.err_flag < 0)
			return (error_msg(info.err_flag));
	}
	else
	{
		ft_putstr_fd("Please input valid data.\n", 2);
		return (1);
	}
	return (0);
}
