#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

int *num;
int suma_total = 0;
pthread_mutex_t mutex;

void cuadrado(int *n)
{
    pthread_mutex_lock(&mutex);
    suma_total += *n * *n;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main(int argc, char * argv[])
{
    int n = atoi(argv[1]);
    pthread_mutex_init(&mutex,NULL);

    pthread_t *th = (pthread_t *)malloc(n*sizeof(pthread_t));
    num = (int *)malloc(n*sizeof(int));
    
    for(int i=0; i<n; i++)
    {
        num[i] = i+1;
        pthread_create(&th[i], NULL, (void *)cuadrado, &num[i]);
    }
    for(int i=0; i<n; i++)
    {
        pthread_join(th[i], NULL);
    }
    printf("Suma_total: %d\n", suma_total);
    pthread_mutex_destroy(&mutex);
    return 0;
}

