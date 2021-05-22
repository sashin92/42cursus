/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:17:21 by sashin            #+#    #+#             */
/*   Updated: 2021/05/23 01:17:27 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		parse_resolution(char *line, t_info *s)
{
	int		i;

	if (s->win.res_x != 0 || s->win.res_y != 0)
		return (-1);
	i = 2;
	while (line[i] == ' ')
		++i;
	while (ft_isdigit(line[i]))
		s->win.res_x = (s->win.res_x * 10) + (line[i++] - '0');
	while (line[i] == ' ')
		++i;
	while (ft_isdigit(line[i]))
		s->win.res_y = (s->win.res_y * 10) + (line[i++] - '0');
	while (line[i] == ' ')
		++i;
	if (s->win.res_x <= 0 || s->win.res_x <= 0 || line[i] != '\0')
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
	while (ft_isdigit(line[i]))
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
	printf("%d %d %d\n", r, g, b);	// printf
	printf("this rgb is 0x%X\n", *rgb);	// printf
	return (0);
}

int			parse_texture(t_info *s, char *line, int **texture)
{
	int		i;
	int		j;
	char	*texture_name;
	void	*texture_img_ptr;
	int		name_len;
	int		fd;

	if (*texture != NULL)
		return (-1);				// 만약 텍스처가 비어있지 않다면(경로지정을 이미 했다면) 에러
	i = 2;
	while (line[i] == ' ')
		++i;
	name_len = 0;
	while (line[i + name_len] != ' ' && line[i + name_len] != '\0')		// 만약 파일이름에 공백이 있다면
		++name_len;
	j = i + name_len;
	while (line[j] != '\0')
		if (line[j++] != ' ')
			return (-1);						// 경로 다음에 다른 문자가 나왔을 때 에러, 스페이스는 허용
	texture_name = (char *)malloc(sizeof(char) * (name_len + 1));
	j = 0;
	while (j < name_len)
		texture_name[j++] = line[i++];
	texture_name[j] = '\0';
	fd = file_open(texture_name);
	printf("%s\n", texture_name);		// printf
	check_extension(texture_name, ".xpm", fd);
	close(fd);
	texture_img_ptr = mlx_xpm_file_to_image(s->mlx.ptr, texture_name, &s->img.w, &s->img.h);
	*texture = (int *)mlx_get_data_addr(texture_img_ptr, &s->img.bpp, &s->img.sl, &s->img.end);
	free(texture_img_ptr);
	free(texture_name);
	return (0);
}


int			parse_map(char *line, t_info *s)
{
	int		i;
	int		len;
	char	**tmp;
	char	*cp_line;

	tmp = (char **)malloc(sizeof(char *) * (s->map.y + 2));


	i = 0;
	while (i < s->map.y)
	{
		tmp[i] = s->map.xy[i];
		++i;
	}
	if (s->map.xy)
		free(s->map.xy);
	cp_line = ft_strdup(line);
	tmp[s->map.y] = cp_line;
	s->map.xy = tmp;
	len = ft_strlen(line);
	int j = 0;
	while (s->map.xy[s->map.y][j])
	{
		if (s->map.xy[s->map.y][j] == 'N')
		{
			s->pos.x = j + 0.5;
			s->pos.y = s->map.y + 0.5;
		}
		++j;
	}
	if (len > s->map.x)
		s->map.x = len;
	s->map.y++;
	return (0);
}
