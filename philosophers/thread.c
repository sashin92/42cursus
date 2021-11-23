#include "philosophers.h"

////////////////////////// 예제코드


int		val = 0;
int		sub = 0;
pthread_mutex_t mutex;


void	*thread_main(void *size)
{
	int		i;
	int		max;
	char	*str;

	i = 0;
	max = 3;

	pthread_mutex_lock(&mutex);
	while (i < max)
	{
		printf("im thread! im alive during %d!!(maxtime : %d)\n", ++i, max);
		val++;
		printf("val? %d\n", val);
		sleep(1);
	}
	str = "DONE!";
	pthread_mutex_unlock(&mutex);
	return ((void *)str);
}

void	*thread_sub(void *size)
{
	int		i;
	int		max;
	char	*str;
	struct timeval start;
	struct timeval end;
	
	i = 0;
	max = 3;
	pthread_mutex_lock(&mutex);
	gettimeofday(&start, NULL);
	printf("where?\n");
	while (i < max)
	{
		printf("im thread! im alive during %d!!(maxtime : %d)\n", ++i, max);
		sub++;
		printf("sub? %d\n", sub);
		sleep(1);
	}
	gettimeofday(&end, NULL);
	str = "DONE!";
	printf("this thread time is %ld + (%d * 10^-6) s\n", (end.tv_sec - start.tv_sec),(end.tv_usec - start.tv_usec));
	pthread_mutex_unlock(&mutex);
	return ((void *)str);
}

int main(void)
{
	pthread_t thread_1;
	pthread_t thread_2;
	void	*str;

	pthread_mutex_init(&mutex, NULL);

	printf("im process, let's go\n");
	pthread_create(&thread_1, NULL, thread_main, NULL);
	pthread_create(&thread_2, NULL, thread_sub, NULL);
	pthread_join(thread_1, &str);
	pthread_join(thread_2, &str);
	
	pthread_mutex_destroy(&mutex);
	printf("process end, val is %d\n return is %s\n", val, (char *)str);
	return (0);
}

