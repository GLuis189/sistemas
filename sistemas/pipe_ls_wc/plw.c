#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int p[2];
    pid_t pid;

    pipe(p);
    pid = fork();
    switch (pid)
    {
    case 0:
        close(p[0]);
        close(STDOUT_FILENO);
        dup(p[1]);
        close(p[1]);
        execlp("ls", "ls", NULL);
        break;
    
    default:
        close(p[1]);
        close(STDIN_FILENO);
        dup(p[0]);
        close(p[0]);
        execlp("wc", "wc", NULL);
        break;
    }


    return 0;
}