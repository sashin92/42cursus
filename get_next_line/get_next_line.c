/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:03:38 by sashin            #+#    #+#             */
/*   Updated: 2021/01/06 15:23:04 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1 // 임시 매크로
#endif

int			get_next_line(int fd, char **line) // <<<<<< LINE이 그래서 뭔데 -> fd에서 읽은 라인을 고대로 **line에 차곡차곡 넣어준다.
{
	int			idx;
	int			line_number;
	char		buf[BUFFER_SIZE];
	char		*str;

	idx = 0;
	line_number = 1;

	if (!(read(fd, buf, BUFFER_SIZE))); // read 리턴 : 읽으면 읽는 바이트, eof면 0, 에러는 -1(errno)
		return (-1);	//못읽으면? An error happened

	if (!(pt = ft_strchr(buf, '\n')))// if (buf != '\n') // 만약 버퍼 안에 개행이 없다면 동작 (버퍼 훑는 함수?)
	{
		read(fd, buf, BUFFER_SIZE); // READ!
	} // buf에 '\n'이 없다면 계속 반복!

	if (buf == '\n')
	{
		seek_in_buf(buf);   // 개행이 있다면 찾아보자!
		line[0] = ft_strdup(읽을라인);
		++line_number;
	}
	
	return (1);
}

// ---------------------- TEST -------------------------

#include <stdio.h>

int main(int argc, char **argv)
{
	char **line;

	line = (char **)malloc(sizeof(char *));
	get_next_line(0, line);
}
