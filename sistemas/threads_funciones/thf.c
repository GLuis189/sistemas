#include <stdio.h>
#include <pthread.h>


void f1(void *arg)
{
    pthread_t tid = pthread_self();
    printf("Thread 1\n");
    sleep(2);
    printf("Fin 1\n");
    pthread_exit(NULL);
}

void f2(void *arg)
{
    pthread_t tid = pthread_self();
    printf("Thread 2\n");
    sleep(5);
    printf("Fin 2\n");
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t tmain = pthread_self();
    pthread_t t1,t2;
    pthread_cond_t cond;
    pthread_attr_init(&cond);
    pthread_create(&t1, &cond,f1,NULL);
    pthread_create(&t2, &cond,f2,NULL);
    pthread_exit(NULL);
    return 0;
}

