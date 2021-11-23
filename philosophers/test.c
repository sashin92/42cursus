#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int Register1;
int Register2;
int Balance = 100;

void *thread_main()
{
    Register1 = Balance;
    Register1 = Register1 + 100;
    Balance = Register1;
    return (NULL);

}

void *thread_sub()
{
    Register2 = Balance;
    Register2 = Register2 + 301;
    Balance = Register2;
    return (NULL);
}


int main(void)
{
	pthread_t thread_1;
	pthread_t thread_2;

	printf("im process, let's go\n");
	pthread_create(&thread_1, NULL, &thread_main, NULL);
	pthread_create(&thread_2, NULL, thread_sub, NULL);
	printf("process end, val is %d\n", Balance);
	return (0);
}
