#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void inf(int s)
{
    printf("Num señal: %d\n", s);
    fflush(stdout);
}

int main()
{
    struct sigaction s5;
    for (;;)
    {
        s5.sa_handler = inf;
        s5.sa_flags = 0;
        sigemptyset(&(s5.sa_mask));
        sigaction(SIGALRM, &s5, NULL);
        alarm(1);
        pause();
    }
    return 0;
}