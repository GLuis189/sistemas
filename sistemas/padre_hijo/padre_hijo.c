#include <stdio.h>

int main()
{
    int a = 3, pid;
    pid = fork();
    switch (pid)
    {
    case 0:
        printf("Soy el hijo ");
        printf("pid=%d, ppid=%d\n", getpid(), getppid());
        printf("Adios\n");
        break;

    default:
        sleep(1);
        printf("Soy el padre ");
        printf("pid=%d, ppid=%d\n", getpid(), getppid());
        printf("Adios\n");
        break;
    }
    return 0;
}