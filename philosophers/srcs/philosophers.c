/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:26:29 by sashin            #+#    #+#             */
/*   Updated: 2021/12/03 13:37:05 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	generate_philos(t_info *info, t_philo **philos)
{
	t_philo	*new;
	int		i;

	new = (t_philo *)malloc(sizeof(t_philo) * info->number_of_philosophers);
	if (new == NULL)
		return (-2);
	i = 0;
	while (i < info->number_of_philosophers)
	{
		new[i].num = i + 1;
		new[i].fork_l = i;
		new[i].fork_r = (i + 1) % info->number_of_philosophers;
		new[i].eat_count = 0;
		new[i].status = THINKING;
		new[i].info = info;
		i++;
	}
	*philos = new;
	return (0);
}

static void	run(t_info *info)
{
	int			i;
	pthread_t	thread;
	t_philo		*philos;

	info->err_flag = generate_philos(info, &philos);
	if (info->err_flag != 0)
		return ;
	info->start_time = ft_get_time();
	if (info->start_time < 0)
	{
		info->err_flag = -5;
		return ;
	}
	i = 0;
	while (i < info->number_of_philosophers)
	{
		philos[i].time = ft_get_time();
		pthread_create(&thread, NULL, thread_function, &philos[i]);
		pthread_detach(thread);
		usleep(100);
		++i;
	}
	monitor(philos);
	info->err_flag = free_and_destroy(philos, info);
}

static int	init_malloc(t_info *info)
{
	int		i;

	info->mutex_fork = malloc(sizeof(pthread_mutex_t) * \
					info->number_of_philosophers);
	if (info->mutex_fork == NULL)
		return (-2);
	i = 0;
	while (i < info->number_of_philosophers)
		if (pthread_mutex_init(&info->mutex_fork[i++], NULL))
			return (-3);
	if (pthread_mutex_init(&info->mutex_print, NULL) || \
		pthread_mutex_init(&info->mutex_count, NULL))
		return (-3);
	return (0);
}

static void	check_parse(t_info *info, int argc, char **argv)
{
	info->number_of_philosophers = ft_atou(argv[1]);
	info->time_to_die = ft_atou(argv[2]);
	info->time_to_eat = ft_atou(argv[3]);
	info->time_to_sleep = ft_atou(argv[4]);
	if (info->number_of_philosophers <= 0 || info->time_to_die == -1 || \
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
		info->err_flag = init_malloc(info);
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
