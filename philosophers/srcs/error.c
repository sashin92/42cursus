/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:52:51 by sashin            #+#    #+#             */
/*   Updated: 2021/11/24 10:38:11 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void		error_msg(int err_flag)
{
	if (err_flag < 0)
	{
		if (err_flag == -1)
			printf("Please input valid arg\n");
		else if (err_flag == -2)
			printf("Malloc error\n");
		else if (err_flag == -3)
			printf("mutex init fail\n");
		else if (err_flag == -4)
			printf("mutex destroy fail\n");
	}
}