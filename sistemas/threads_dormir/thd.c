#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void* dormir(void* arg)
{
    sem_wait(&mutex);
    printf("\n Primero..\n");
    sleep(4);
    printf("\n Segundo...\n");
    sem_post(&mutex);
}

int main()
{
    sem_init(&mutex, 0 ,1);
    pthread_t th1, th2;
    pthread_create(&th1, NULL, dormir, NULL);
    sleep(2);
    pthread_create(&th2, NULL, dormir, NULL);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    sem_destroy(&mutex);
    return 0;
}