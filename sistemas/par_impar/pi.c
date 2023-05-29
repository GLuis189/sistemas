#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int dato_compartido = 0;
int es_par = 0;
pthread_mutex_t m;
pthread_cond_t cI, cP;

void pares()
{
    for(int i=0; i<50; i++ )
    {
        pthread_mutex_lock(&m);
        if(es_par==0)
        {
            pthread_cond_wait(&cP, &m);
        }
        printf("Thread1: %d\n", dato_compartido++);
        es_par = 0;
        pthread_cond_signal(&cI);
        pthread_mutex_unlock(&m);
    }
    pthread_exit(1);
}

void impares()
{
for(int i=0; i<50; i++ )
    {
        pthread_mutex_lock(&m);
        if(es_par==1)
        {
            pthread_cond_wait(&cI, &m);
        }
        printf("Thread2: %d\n", dato_compartido++);
        es_par = 1;
        pthread_cond_signal(&cP);
        pthread_mutex_unlock(&m);
    }
    pthread_exit(1);
}

int main(void)
{
    // decIaraciones para los threads
    pthread_t th1, th2;
    pthread_mutex_init(&m, NULL);
    pthread_cond_init(&cI, NULL);
    pthread_cond_init(&cP, NULL);

    //crear lso threads
    pthread_create(&th1, NULL, (void *)pares, NULL);
    pthread_create(&th2, NULL, (void *)impares, NULL);

    //esperar a que terminen los threads
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    //liberar espacio
    pthread_mutex_destroy(&m);
    pthread_cond_destroy(&cI);
    pthread_cond_destroy(&cP);
}
