#include "test.h"

///////////////// about readline
// int main(int argc, char **argv)
// {
// 	char **input;

// 	input = (char **)malloc(sizeof(char *) * 3);
// 	while (1)
// 	{
// 		input[0] = readline("sashin$>");
// 		printf(" -> %s\n", input[0]);

// 		add_history(input[0]);
// 		free(input[0]);
// 	}
// }


/////////////// about fork()

// int main(int argc, char **argv)
// {
//     char *new;

//     new = malloc(100);
//     new = "/bin/ls";
//     argv[0] = new;
//     execve(argv[0], argv, NULL);
//     return 0;
// }
int main(void)
{
		int fd1;
		int ret;

		fd1 = open("im_fd1", O_RDWR | O_CREAT);
		ret = dup2(fd1, STDOUT_FILENO);
		printf("fd1 :%d, ret:%d\n",fd1,ret);
		ret = dup2(STDERR_FILENO, fd1);
		write(fd1, "this is stderr?\n", 16);
		printf("where is this print?, ret is %d, ttyslot? %d %d\n", ret, ttyslot(), ttyslot());
		close(fd1);
}