/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:17:21 by sashin            #+#    #+#             */
/*   Updated: 2021/05/17 21:37:15 by sashin           ###   ########.fr       */
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
	{
		printf("잘못된 해상도값\n");
		return (-2);
	}
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
	printf("this rgb is %o\n", *rgb);
	return (0);
}

int			parse_path(char *line, char **texture)
{
	int		i;
	int		j;
	char	*path;
	int		path_len;

	if (*texture != NULL)
		return (-1);				// 만약 텍스처가 비어있지 않다면(경로지정을 이미 했다면) 에러
	i = 2;
	while (line[i] == ' ')
		++i;
	path_len = 0;
	while (line[i + path_len] != ' ' && line[i + path_len] != '\0')		// 만약 파일이름에 공백이 있다면
		++path_len;
	j = i + path_len;
	while (line[j] != '\0')
		if (line[j++] != ' ')
			return (-1);						// 경로 다음에 다른 문자가 나왔을 때 에러
	path = (char *)malloc(sizeof(char) * (path_len + 1));
	j = 0;
	while (j < path_len)
		path[j++] = line[i++];
	path[j] = '\0';
	*texture = path;
	return (0);
}
