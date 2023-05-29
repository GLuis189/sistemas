#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <string.h>

int suma = 0;
int v[100];

sem_t mutex;

void sumar()
{
    for (int i = 0; i<100;i++)
    {
        sem_wait(&mutex);
        suma += v[i];
        sem_post(&mutex);
    }
    pthread_exit(1);
}

int main()
{
    for(int i; i<100;i++){v[i] = 1;}
    pthread_t t1,t2;
    sem_init(&mutex,0,1);
    pthread_create(&t1, NULL, sumar, NULL);
    pthread_create(&t2, NULL, sumar, NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&mutex);
    printf("%d\n", suma);
    return 0;
}