#include <stdio.h>

#define N 10


int main()
{
    for(int i; i<N; i++)
    {
        int pid = fork();
        if(pid==0)
        {
            printf("Arranca\n");
            sleep(10);
            exit(0);
        }
        else{
            wait(0);
        }
    }
    return 0;
}