/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:34:43 by sashin            #+#    #+#             */
/*   Updated: 2021/06/18 21:37:47 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	char_to_signal(int server_pid, char c)
{
	int		power;
	char	binary;

	binary = c;
	power = 0;
	while (power <= 7)
	{
		if (binary % 2 == 0)
			kill(server_pid, SIGUSR1);
		else if (binary % 2 == 1)
			kill(server_pid, SIGUSR2);
		binary = binary / 2;
		++power;
		usleep(100);
	}
}

static void	push_str(int server_pid, char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		char_to_signal(server_pid, s[i]);
		++i;
	}
}

int			main(int argc, char **argv)
{
	int		server_pid;

	server_pid = 0;
	if (argc == 1 || argc == 2)
		ft_putstr("Input PID, Contents.\n");
	else if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (server_pid == -1)
		{
			ft_putstr("wrong pid.\n");
			return (0);
		}
		push_str(server_pid, argv[2]);
	}
	else
		ft_putstr("Too much arguments.\n");
	return (0);
}
