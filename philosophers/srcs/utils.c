/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:18:50 by sashin            #+#    #+#             */
/*   Updated: 2021/12/02 18:43:18 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atou(char *str)
{
	long long	val;
	int			i;

	if (str == NULL)
		return (-1);
	val = 0;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = (val * (long long)10) + (long long)(str[i] - '0');
		if (val > 604800000)
			return (-1);
		++i;
	}
	if (str[i] != '\0' || (str[0] == '-' && val != 0))
		return (-1);
	return (val);
}

void	ft_putstr_fd(char *str, int fd)
{
	int		len;

	len = 0;
	if (str == NULL)
	{
		write(2, "putstr_err\n", 11);
		return ;
	}
	while (str[len])
		++len;
	write(fd, str, len);
	return ;
}

void	*ft_memset(void *src, int c, size_t size)
{
	size_t		idx;

	idx = 0;
	while (idx < size)
	{
		((unsigned char *)src)[idx] = (unsigned char)c;
		++idx;
	}
	return (src);
}

long long	ft_get_time(void)
{
	struct timeval		t1;
	long long			ret;

	ret = gettimeofday(&t1, NULL);
	if (ret < 0)
		return (ret);
	ret = (t1.tv_sec * 1000) + (t1.tv_usec / 1000);
	return (ret);
}

int	free_and_destroy(t_philo *philo, t_info *info)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (i < info->number_of_philosophers)
		if (pthread_mutex_destroy(&info->mutex_fork[i++]))
			return (-4);
	if (pthread_mutex_destroy(&info->mutex_print))
		return (-4);
	free(info->mutex_fork);
	free(philo);
	return (0);
}
