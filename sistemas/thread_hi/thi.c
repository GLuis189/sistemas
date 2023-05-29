#include <stdio.h>
#include <pthread.h>


void imprimir()
{
    for (int i = 0; i < 3; i++)
    {
        printf("Thread says hi! \n");
        sleep(1);
    }
    printf("Thread end. \n");
}

int main()
{
    pthread_t imprimir_th;
    if (pthread_create(&imprimir_th, NULL, imprimir, NULL) == -1)
    {
        perror("Error creando thread. n");
        abort();
    }
    printf("Wait to finish. \n");
    if (pthread_join(imprimir_th, NULL) == -1)
    {
        perror("Error join. \n");
        abort();
    }
    return 0;
}