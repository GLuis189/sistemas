#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>

#define BUFFSIZE 20
#define DATOS_A_PRODUCIR 5

pthread_t th1,th2;
sem_t elementos;
sem_t huecos;

int buffer[BUFFSIZE];

void productor()
{
    int pos = 0;
    int dato;
    for(int i=0; i <  DATOS_A_PRODUCIR; i++)
    {
        dato = i;
        sem_wait(&huecos);
        buffer[pos] = dato;
        printf("Produce %d\n", dato);
        pos = (pos + 1) % BUFFSIZE;
        sem_post(&elementos);
    }
    pthread_exit(0);
}

void consumidor()
{
    int pos = 0;
    int dato;
    for (int i = 0; i < DATOS_A_PRODUCIR; i++)
    {
        sem_wait(&elementos);
        dato = buffer[pos];
        pos = (pos + 1) % BUFFSIZE;
        sem_post(&huecos);
        printf("Consume %d\n", dato);
    }
    pthread_exit(0);
}

int main()
{
    sem_init(&elementos, 0, 0);
    sem_init(&huecos , 0, BUFFSIZE);
    pthread_create(&th1, NULL, productor, NULL);
    pthread_create(&th2, NULL, consumidor, NULL);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    sem_destroy(&huecos);
    sem_destroy(&elementos);
    return 0;
}