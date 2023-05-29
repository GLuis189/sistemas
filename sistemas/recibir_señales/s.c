#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void capturarSeñal(int s)
{
 printf("Señal recibida en el hijo %d\n",s);
}

int main()
{
 struct sigaction sa1;

 int pid = fork();
 if (pid!=0)
 {
 sleep(10);
 kill(pid,SIGUSR1);
 exit(0);
 }
 else{
 sa1.sa_handler = capturarSeñal;
 sa1.sa_flags = 0;
 sigemptyset(&(sa1.sa_mask));
 sigaction(SIGUSR1, &sa1, NULL);
 pause();

 }
 return 0;
}
