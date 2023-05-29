#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int p[2];
    pid_t pid;

    if (pipe(p)<0) 
    {
        perror("error pipe");
        exit(1);
    }

    pid = fork();
    switch (pid)
    {
    case -1:
        perror("error fork");
        break;
    case 0:
        dup2(p[1],1);
        close(p[0]);
        execlp("./prog_esc", "./prog_esc", NULL);
        break;
    default:
        dup2(p[0],0);
        close(p[1]);
        execlp("./prog_lec", "./prog_lec", NULL);
        break;
    }
}