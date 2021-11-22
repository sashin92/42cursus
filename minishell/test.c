#include "test.h"


int main()
{
	char *input;

	while (1)
	{
		input = readline("sashin$>");
		rl_on_new_line();
		printf(" -> %s\n", input);

		add_history(input);
		free(input);
	}
}