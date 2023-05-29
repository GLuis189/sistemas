#include <stdio.h>
#include <pthread.h>

int suma_total = 0;

void sumar()
{
    int j = suma_total;
    j = j + 100;
    sleep(1);
    suma_total = j;
}

int main(int argc, char *argv[])
{
    pthread_t threads[10];
    for (int i = 0; i<10; i++)
    {
        pthread_create(&threads[i], NULL, (void *)sumar, NULL);
    }
    for (int i = 0; i<10; i++)
    {
        pthread_join(threads[i], NULL);
    }
    printf("%d\n", suma_total);
    return 0;

}