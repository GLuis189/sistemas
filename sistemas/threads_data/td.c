#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

int data = 0; 
int t1()
{
    int a=0;
    sem_wait(&mutex);
    a = data; 
    a = a + 1;
    data = a; 
    sem_post(&mutex);
}

int t2()
{
   int b=0;
   sem_wait(&mutex);
   b = data; 
   b = b + 1;
   data = b;
   sem_post(&mutex);
}

int main()
{   
    pthread_t th1, th2;
    sem_init(&mutex, 0,1);
    pthread_create(&th1, NULL, t1, NULL);
    pthread_create(&th2, NULL, t2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&mutex);
    printf("%d", data);
    return 0;
}