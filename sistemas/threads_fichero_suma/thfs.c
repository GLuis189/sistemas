#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define NUMBERS_PER_THREAD 10

int sum[NUM_THREADS] = {0};

void* threadFunc(void* arg) {
    int threadIndex = *(int*)arg;
    int start = threadIndex * NUMBERS_PER_THREAD;
    int end = start + NUMBERS_PER_THREAD;
    FILE *file = fopen("num.txt", "r");
    if (file == NULL) {
        printf("Error al abrir el archivo num.txt\n");
        exit(1);
    }
    for (int i = 0; i < end; i++) {
        int num;
        if (fscanf(file, "%d", &num) != 1) {
            printf("Error al leer el archivo num.txt\n");
            exit(1);
        }
        if (i >= start) {
            sum[threadIndex] += num;
        }
    }
    fclose(file);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadIndex[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        threadIndex[i] = i;
        pthread_create(&threads[i], NULL, threadFunc, &threadIndex[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    int totalSum = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        totalSum += sum[i];
    }
    printf("La suma total es: %d\n", totalSum);
    return 0;
}
