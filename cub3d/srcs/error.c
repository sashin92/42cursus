/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:48:17 by sashin            #+#    #+#             */
/*   Updated: 2021/06/08 18:49:56 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_error_two(int err)
{
	if (err == -11)
		printf("Can't find 'F' line.\n");
	else if (err == -12)
		printf("Can't find 'C' line.\n");
	else if (err == -13)
		printf("Can't find 'R' line.\n");
	else if (err == -14)
		printf("Wrong identifier in cub file.\n");
	else if (err == -15)
		printf("Invalid map!\n");
}

int			check_error(int err)
{
	if (err == -1)
		printf("multiple texture line in cub file.\n");
	else if (err == -3)
		printf("multiple 'C' or 'F' is in cub file.\n");
	else if (err == -4)
		printf("please input valid rgb value. color range: [0, 255]\n");
	else if (err == -5)
		printf("you can't use tab in texture line.\n");
	else if (err == -6)
		printf("the map content has to be the last.\n");
	else if (err == -7)
		printf("Can't find 'NO' line.\n");
	else if (err == -8)
		printf("Can't find 'SO' line.\n");
	else if (err == -9)
		printf("Can't find 'EA' line.\n");
	else if (err == -10)
		printf("Can't find 'WE' line.\n");
	check_error_two(err);
	return (-1);
}
