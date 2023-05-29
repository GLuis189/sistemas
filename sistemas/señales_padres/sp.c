#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void tratars1(int s)
{
    printf("Tratar señal SIGUSR1\n");
    time(NULL);
}

void tratars2(int s)
{
    printf("Tratar señal SIGCHLD\n");
    time(NULL);
}

int main()
{
    int pid;
    pid = fork();
    struct sigaction sa2,sa3;
    
    if (pid == 0)
    {
        sleep(2);
        kill(getppid(), SIGUSR1);
        sleep(3);
        time(NULL);
    }
    else
    {
        sa2.sa_handler = tratars1;
        sa2.sa_flags = 0;
        sigemptyset(&(sa2.sa_mask));
        sigaction(SIGUSR1, &sa2, NULL);

        sa3.sa_handler = tratars2;
        sa3.sa_flags = 0;
        sigemptyset(&(sa3.sa_mask));
        sigaction(SIGCHLD, &sa3, NULL);
    pause();
    pause();
    
    }
    return 0;
}