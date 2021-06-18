/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:34:46 by sashin            #+#    #+#             */
/*   Updated: 2021/06/13 18:31:12 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include "stdio.h"
void	pull_sig(int signum)
{
	printf("haha\n");
	exit(1);
}


#include <stdio.h>
int		main(void)
{

	signal(SIGUSR1, &pull_sig);
	printf("PID: %d\n", getpid());
	while (1);
}