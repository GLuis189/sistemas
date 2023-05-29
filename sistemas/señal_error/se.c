#include <stdio.h>
#include <signal.h>

void capturarSeñal(int segnal)
{
    printf("Error\n");
    signal(SIGSEGV, SIG_DFL);
}

int main()
{
    int *p;
    signal(SIGSEGV, capturarSeñal);
    p=0;
    *p=5;
    return 0;
}