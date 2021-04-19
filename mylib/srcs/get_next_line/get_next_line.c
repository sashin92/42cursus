/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 20:27:40 by sashin            #+#    #+#             */
/*   Updated: 2021/04/19 16:43:46 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

int				gnl_input_line(char **line, char **stack, char *pt)
{
	char			*temp;

	if (ft_strchr(*stack, '\n') != NULL)
	{
		*pt = '\0';
		*line = ft_strdup(*stack);
		temp = ft_strdup((char *)(pt + 1));
		free(*stack);
		*stack = temp;
	}
	else
	{
		*line = ft_strdup(*stack);
		free(*stack);
		*stack = NULL;
		return (0);
	}
	return (1);
}

void			gnl_strjoin_free(char **stack, char *buf)
{
	char			*temp;

	temp = ft_strjoin(*stack, buf);
	free(*stack);
	*stack = temp;
}

int				get_next_line(int fd, char **line)
{
	static char		*stack[1024];
	char			*buf;
	char			*pt;
	int				rd_size;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 ||
		!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (stack[fd] == NULL)
	{
		if ((rd_size = read(fd, buf, BUFFER_SIZE)) == -1)
			return (-1);
		buf[rd_size] = '\0';
		stack[fd] = ft_strdup(buf);
	}
	while ((pt = ft_strchr(stack[fd], '\n')) == NULL &&
				(rd_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rd_size] = '\0';
		gnl_strjoin_free(&stack[fd], buf);
	}
	free(buf);
	return (gnl_input_line(line, &stack[fd], pt));
}
