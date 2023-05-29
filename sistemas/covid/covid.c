#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

struct persona {
    char nombre[100];
    char telefono[24];
    char anyo[5];
    char mes[5];
    char dia[5];
};

int main()
{
    FILE* fd;
    struct persona p;
    char directorio[17];
    char fichero[130];
    if ((fd = fopen("listado.txt", "r"))<0)
    {
        perror("No se ha podido abrir el archivo");
        return -1;
    }
    while(fscanf(fd, "%s %s %s %s %s", p.nombre, p.telefono, p.anyo, p.mes, p.dia)!= EOF)
    {
        sprintf(directorio, "%s_%s_%s", p.anyo, p.mes, p.dia);
        sprintf(fichero, "%s-%s.txt", p.telefono, p.nombre);
        mkdir(directorio, 0777);
        chdir(directorio);
        creat(fichero, 0777);
        chdir("..");
    }
    return 0;
}