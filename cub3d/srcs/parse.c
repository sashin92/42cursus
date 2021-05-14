/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:17:21 by sashin            #+#    #+#             */
/*   Updated: 2021/05/14 16:25:26 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		parse_resolution(char *line, t_info *info)
{
	int		i;

	if (info->win.res_x != 0 || info->win.res_y != 0)	// 해상도 중복 체크
		return (-1);
	i = 2;
	while (line[i] == ' ')
		++i;
	while (ft_isdigit(line[i]))
		info->win.res_x = (info->win.res_x * 10) + (line[i++] - '0');
	while (line[i] == ' ')
		++i;
	while (ft_isdigit(line[i]))
		info->win.res_y = (info->win.res_y * 10) + (line[i++] - '0');
	while (line[i] == ' ')
		++i;
	if (info->win.res_x <= 0 || info->win.res_x <= 0 || line[i] != '\0')
		return (-2);
	return (0);
}

int		parse_rgb(char *line, int *rgb)
{
	int		i;
	int		r;
	int		g;
	int		b;

	i = 2;
	r = 0;
	g = 0;
	b = 0;
	while (line[i] == ' ')
		++i;
	while (ft_isdigit(line[i]))
		r = (r * 10) + (line[i++] - '0');
	if (line[i] == ',')
		++i;
	while (ft_isdigit(line[i]))						// 124,,5 라고 넣을 때에는?
		g = (g * 10) + (line[i++] - '0');
	if (line[i] == ',')
		++i;
	while (ft_isdigit(line[i]))
		b = (b * 10) + (line[i++] - '0');
	while (line[i] == ' ')
		++i;
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255 || line[i] != '\0')
		return (-2);
	*rgb = (r * 256 * 256) + (g * 256) + b;
	printf("this rgb is %d\n", *rgb);
	return (0);
}

// int		parse_map(char *line, t_info *info)
// {
// }