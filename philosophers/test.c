#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>


pthread_mutex_t mutex;

long long	ft_get_time(void)
{
    static int a = 1;

	struct timeval		t1;
	long long			ret;

	ret = gettimeofday(&t1, NULL);
	if (ret == -1)
		return (ret);
	ret = (t1.tv_sec * 1000) + (t1.tv_usec);
	return (ret);
}

void pr(int *i)
{
    char a = *i + '0';
    write(1, &a, 1);
}

void *thread_main(void *i)
{
    long long t1;
    long long t2;

    pthread_mutex_lock(&mutex);
    t1 = ft_get_time();
    pr(i);
    t2 = ft_get_time();
    printf("time diff is %lld\n", t2 - t1);
    pthread_mutex_unlock(&mutex);

    return (NULL);
}

void run(void)
{

	pthread_t *thread;

    thread = (pthread_t *)malloc(sizeof(pthread_t) * 10);
    pthread_mutex_init(&mutex, NULL);

	printf("im process, let's go\n");
    int i = 0;
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    int f = 6;
    int g = 7;
    int h = 8;
    int j = 9;

    

    pthread_create(&thread[1], NULL, &thread_main, &a);
    printf("a\n");
    pthread_create(&thread[1], NULL, &thread_main, &b);
    printf("aaaa\n");
    pthread_create(&thread[3], NULL, &thread_main, &c);
    printf("a\n");
    pthread_create(&thread[4], NULL, &thread_main, &d);
    printf("abdfbbfdb\n");
    pthread_create(&thread[5], NULL, &thread_main, &e);
    printf("a\n");
    pthread_create(&thread[6], NULL, &thread_main, &f);
    printf("aqqq\n");
    pthread_create(&thread[7], NULL, &thread_main, &g);
    printf("a\n");
    pthread_create(&thread[8], NULL, &thread_main, &h);
    printf("aaaaaaaa\n");
    pthread_create(&thread[9], NULL, &thread_main, &j);

    pthread_detach(thread[2]);
    pthread_join(thread[2], NULL);
    free(thread);
    // 8코어 8스레드 CPU;
    // 8스레드;

    // 프로그램1(pthread x);
    // -코어 1개만 조짐

    // 프로그램2(pthread 4개);
    // {
    //     8개의 스레드 중 남는 곳에 각각 들어가서 처리
    // }

    sleep(1);

}

int main(void)
{
    run();

    while (1);
    return (0);
}
