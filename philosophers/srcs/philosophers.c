/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:26:29 by sashin            #+#    #+#             */
/*   Updated: 2021/11/27 19:27:15 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		philo_free_mutex_destroy(t_philo **new, int idx)
{
	int		i;
	int		ret;
	int		flag;

	i = 0;
	flag = 0;
	while (i < idx)
	{
		ret = pthread_mutex_destroy(&new[i]->info->fork[i]);
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
		new[idx].num = idx + 1;
		new[idx].fork_l = idx + 1;
		new[idx].fork_r = (idx + 1) % info->number_of_philosophers + 1;
		new[idx].eat_count = 0;
		new[idx].status = THINKING;
		new[idx].info = info;
		flag = pthread_mutex_init(&new[idx].info->fork[idx], NULL);
		if (flag != 0)
			flag = philo_free_mutex_destroy(&new, idx);
		idx++;
	}
	*philo = new;
	return (flag);
}

static void		run(t_info *info)
{
	int		i;
	t_philo	*philo;

	info->err_flag =  generate_philo(info, &philo);
	if (info->err_flag != 0)
		return ;
	i = 0;
	info->start_time = ft_get_time();
	if (info->start_time < 0)
		info->err_flag = -5;
	while (info->err_flag == 0 && i < info->number_of_philosophers)
	{
		philo[i].time = info->start_time;
		pthread_create(&philo[i].thread, NULL, thread_main, &philo[i]);
		pthread_detach(philo[i].thread);
		++i;
	}
}

static void		check_parse(t_info *info, int argc, char **argv)
{
	info->err_flag = 0;
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
		if (info->number_of_times_each_philosopher_must_eat == -1)
			info->err_flag = -1;
	}
	else
		info->number_of_times_each_philosopher_must_eat = 0;
	info->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
					info->number_of_philosophers);
	if (info->fork == NULL)
		info->err_flag = -1;
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
			return (error_msg(info.err_flag));
	}
	else
	{
		ft_putstr_fd("Please Input valid data.\n", 2);
		return (1);
	}
	return (0);
}
