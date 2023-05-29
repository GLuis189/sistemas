#include <stdio.h>

int main()
{
    printf("Hola\n");
    fork();
    printf("Uno\n");
    fork();
    printf("Dos pid=%d\n", getpid());
    return 0;
}