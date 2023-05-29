#include <stdio.h>
#include <fcntl.h>
#define BUFSIZE 512
#define PERM 0644

int main()
{   
    int fd, nread;
    if ((fd = creat("registro.txt", PERM)) < 0)
    {
        perror("Error");
        close(fd);
        return -1;
    }

    int n_alumn;
    printf("Introduce el número de alumnos: ");
    scanf("%d", &n_alumn);
    
    char nombres[n_alumn];
    char notas[n_alumn * 3];
    for(int i = 0; i<n_alumn; i++)
    {
        printf("Introduce el nombre del alumno nª %d: ", i+1);
        scanf("&d", nombres[i]);
        write(fd, nombres[i], sizeof(nombres[i]));
        for(int j = 0; j<3; j++)
        {
            printf("Intordude la nota nº %d: ", j + 1);
            scanf("%f", notas[i+j]);
            write(fd, notas[i+j], sizeof(notas[i+j]));
        }
    }
    close(fd);
    for(int i; i<n_alumn; i++){
        printf("Alumno: %s, tiene de media %f", nombres[i], (notas[i]+notas[i+1]+notas[i+2])/3);
    }
    return 0;
}