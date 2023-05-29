#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int pid;
    pid = fork();
    if(pid == 0)
    {
        close(STDOUT_FILENO);
        open("salida.txt", O_RDWR | O_CREAT, 0660);
        execvp(argv[1], &argv[1]);  
    }
    wait(NULL);
}