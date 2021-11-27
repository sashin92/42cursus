/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:18:50 by sashin            #+#    #+#             */
/*   Updated: 2021/11/27 10:26:45 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		ft_atou(char *str)
{
	long long	val;
	int			i;

	if (str == NULL)
		return (-1);
	val = 0;
	i = 0;
	if (str[i] == '+' ||str[i] == '-')
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

int		ft_relative_time(struct timeval t1, struct timeval t2)
{
	int		sec;
	int		dot_msec;
	int		total_time;

	sec = t2.tv_sec - t1.tv_sec;
	dot_msec = (t2.tv_usec - t1.tv_usec) / 1000;
	total_time = (sec * 1000) + dot_msec;
	return (total_time);
}


long long	ft_get_time(void)
{
	struct timeval		t1;
	long long			ret;

	ret = gettimeofday(&t1, NULL);
	if (ret == -1)
		return (ret);
	ret = (t1.tv_sec * 1000) + (t1.tv_usec / 1000);
	return (ret);
}