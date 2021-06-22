/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:34:46 by sashin            #+#    #+#             */
/*   Updated: 2021/06/20 21:45:59 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

#include <stdio.h>
static void		handle_signal(int signum)
{
	static char	c;
	static int	power;

	if (signum == SIGUSR2)
		c = c + ft_power(2, power);
	++power;
	if (power == 8)
	{
		ft_putchar(c);
		c = 0;
		power = 0;
	}
}

static int		print_pid(void)
{
	char		*ser_pid;

	ser_pid = ft_itoa(getpid());
	if (ser_pid == NULL)
		return (-1);
	ft_putstr("PID: ");
	ft_putstr(ser_pid);
	ft_putchar('\n');
	free(ser_pid);
	return (0);
}

static void		pull_str(void)
{
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
}

int				main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
	{
		if (print_pid() == -1)
		{
			ft_putstr("malloc fail.\n");
			return (0);
		}
		pull_str();
		while (1)
			pause();
	}
	else
		ft_putstr("Don't input arguments.\n");
	return (0);
}
