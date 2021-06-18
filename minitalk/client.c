/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:34:43 by sashin            #+#    #+#             */
/*   Updated: 2021/06/13 18:56:26 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include "stdio.h"
void	push_sig(int signum)
{
	printf("받아랏\n");
	exit(1);
}


#include <stdio.h>
int		main(int argc, char **argv)
{
	signal(SIGUSR1, &push_sig);
	if (argc == 1)
		write(1, "Input PID, description.\n", 24);


	while (1);
}