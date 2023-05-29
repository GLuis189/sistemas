#include <stdio.h>
#include <fcntl.h>
#define BUFSIZE 512
#define PERM 0644

int copyfile(char *name1, char *name2)
{
    int infile, outfile, nread;
    char buffer[BUFSIZE];
    if ((infile = open(name1, O_RDONLY)) < 0)
    {
        return -1;
    }
    if ((outfile = creat(name2, PERM)) < 0)
    {
        close(infile);
        return -1;
    }
    while ((nread = read(infile, buffer, BUFSIZE)) > 0)
    {
        if (write(outfile, buffer, nread)<nread)
        {
            close(infile);
            close(outfile);
            return -1;
        }
    }
    if (nread == -1)
    {
        return -1;
    }
    close(infile);
    close(outfile);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        perror("mal argumentos");
        return -1;
    }
    int result = copyfile(argv[1], argv[2]);
    if (result < 0)
    {
        perror("error");
        return -1;
    }
    return 0;
}