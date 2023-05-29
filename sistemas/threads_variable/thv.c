#include <stdio.h>
#include <pthread.h>

typedef struct {
    int id;
} parm;

void th_func(void *arg)
{
    parm *p = (parm *)arg;
    printf("Hello from thread %d\n", p->id);
}

int main(int argc, char *argv[])
{
    pthread_t *threads;
    pthread_attr_t pthread_custom_attr;
    parm *p;

    int n =atoi(argv[1]);
    threads = (pthread_t *)malloc(n*sizeof(*threads));
    pthread_attr_init(&pthread_custom_attr);
    p = (parm *)malloc(sizeof(parm)*n);
    for (int i; i<n; i++)
    {
        p[i].id=i;
        if(pthread_create(&threads[i], &pthread_custom_attr, th_func, (p+i)) == -1) {abort();}
    }
    for (int i; i<n; i++)
    {
        if(pthread_join(threads[i],NULL) == -1) {abort();}
    }

    return 0;
}