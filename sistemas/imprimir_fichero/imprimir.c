#include <stdio.h>
#include <fcntl.h>
#define BUFSIZE 512


int imprimir(char *file){
    int fd, nread;
    char buff[BUFSIZE];
    if ((fd = open(file, O_RDONLY)) < 0)
    {
        perror("No se ha encontrado el fichero\n");
        close(fd);
        return -1;
    }
    while ((nread = read(fd, buff, BUFSIZE))>0)
    {
        printf("%s", buff);
    }
    close(fd);
    return 0;
}

int main(int argc, char *argv[]){
    imprimir(argv[1]);
    return 0;
}