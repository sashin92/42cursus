#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char *line;
	int fd;
	int gnl;

	fd = open("tes.txt", O_RDONLY);
	while (1)
	{
		gnl = get_next_line(fd, &line);
		printf("%s\n", line);
		free(line);
		if (gnl != 1)
			break ;
	}
	while (1);
}