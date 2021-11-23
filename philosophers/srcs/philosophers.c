/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:26:29 by sashin            #+#    #+#             */
/*   Updated: 2021/11/23 19:15:01 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo		*generate_philo(int number_of_philosophers)
{
	t_philo	*new;

	new = (t_philo *)malloc(sizeof(t_philo) * number_of_philosophers);
	if (new == NULL)
		return (NULL);
	return (new);
}

void	thread_main(void)
{
	
}

void		run(t_info *info)
{
	int		i;

	i = 0;
	while (i++ < info->number_of_philosophers)
	{
		philo.thread = generate_thread();
		philo.thread = philo.next;
	}
	i = 0;
	while (i++ < info->number_of_philosophers)
	{
		philo_gogo();
	}
	
}




int		check_parse(t_info *info, int argc, char **argv)
{
	info->number_of_philosophers = ft_atoi_nosign(argv[1]);
	info->time_to_die = ft_atoi_nosign(argv[2]);
	info->time_to_eat = ft_atoi_nosign(argv[3]);
	info->time_to_sleep = ft_atoi_nosign(argv[4]);
	if (info->number_of_philosophers == -1 || info->time_to_die == -1 || \
		info->time_to_eat == -1 || info->time_to_sleep == -1)
		return (-1);
	if (argc == 6)
	{
		info->number_of_times_each_philosopher_must_eat = ft_atoi_nosign(argv[5]);
		if (info->number_of_times_each_philosopher_must_eat == -1)
			return (-1);
	}
	return (0);
}



int		main(int argc, char **argv)
{
	t_info	info;

	if (argc == 5 || argc == 6)
	{
		if (check_parse(&info, argc, argv) == -1)
		{
			printf("invalid arg.\n");
			return (1);
		}
		run(&info);
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
