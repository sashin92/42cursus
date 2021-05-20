/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 22:26:23 by sashin            #+#    #+#             */
/*   Updated: 2021/05/20 22:36:57 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double			deg_to_rad(double deg)
{
	double	rad;

	rad = deg * M_PI / 180.0;
	return (rad);
}

int				rad_step(double rad)
{
	if (fabs(rad) <= EPS)
		return (0);
	if (rad > 0)
		return (1);
	else
		return (-1);
}

double			l2dist(double x0, double y0, double x1, double y1)
{
	double	dx;
	double	dy;

	dx = fabs(x1 - x0);
	dy = fabs(y1 - y0);
	return (sqrt(dx * dx + dy * dy));
}