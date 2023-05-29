#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define N 3

pthread_t th1, th2;
pthread_attr_t attr;
pthread_mutex_t impresor = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t imprimirHola;
pthread_cond_t imprimirMundo;

int impHola = 1;

void imprimir(void *arg)
{
    char cadena_hola[] = "Hola ";
    char a[12];
    pthread_mutex_lock(&impresor);
    strcpy(a, (char*)arg);
    if (strcmp(a, cadena_hola)==0)
    {
        while(impHola==0)
        {
            pthread_cond_wait(&imprimirHola,&impresor);
        }
        printf("%s",a);
        impHola = 0;
        pthread_cond_signal(&imprimirMundo);
    } else{
        while(impHola==1)
        {
            pthread_cond_wait(&imprimirMundo, &impresor);
        }
        printf("%s",a);
        impHola = 1;
        pthread_cond_signal(&imprimirHola);
    }
    pthread_mutex_unlock(&impresor);
    pthread_exit(NULL);
}

int main()
{
    pthread_cond_init(&imprimirHola, NULL);
    pthread_cond_init(&imprimirMundo, NULL);

    char cadena_hola[] = "Hola ";
    char cadena_mundo[] = "mundo \n";

    pthread_attr_init(&attr);

    for(int i=0; i<N;i++)
    {
        pthread_create(&th2, &attr, imprimir, (void *)cadena_mundo);
        pthread_create(&th1, &attr, imprimir, (void *)cadena_hola);
    }
    pthread_exit(NULL);
}


