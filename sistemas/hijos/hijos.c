#include <stdlib.h>

int main()
{
    int i, pid;
    for(i=1; i<=2; i++)
    {
        pid = fork();
        if(pid==0)
        {
            printf("Soy el hijo %d\n", i);
            exit(0);
        }
    }
    return 0;
}