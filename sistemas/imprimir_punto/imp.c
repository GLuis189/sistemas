#include <stdio.h>
#include <pthread.h>

int myglobal = 0;

void imprimir_punto()
{
    for(int i = 0; i<20; i++)
    {
        int j = myglobal;
        j = j + 1;
        printf(".");
        fflush(stdout);
        sleep(1);
        myglobal = j;
    }
}

int main()
{
    pthread_t mythread;
    if (pthread_create(&mythread, NULL, imprimir_punto,NULL) == -1) {abort();}
    for(int i; i < 20; i++)
    {
        myglobal = myglobal + 1;
        printf("o");
        fflush(stdout);
        sleep(1);
    }
    if ( pthread_join(mythread,NULL)== -1) {abort();}
    printf("\nMyglobal = %d\n", myglobal);
    return 0;
}