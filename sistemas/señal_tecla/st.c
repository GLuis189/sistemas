#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void tratarsa4(int s)
{
    printf("Tecla\n");
}

int main()
{
    struct sigaction sa4;
    sa4.sa_handler = tratarsa4;
    sa4.sa_flags = 0;
    sigemptyset(&(sa4.sa_mask));
    sigaction(SIGALRM,&sa4,NULL);

    int a = 33;
    alarm(3);
    scanf("%d", &a);
    return 0;
}