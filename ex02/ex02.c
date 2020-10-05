#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void filho_fim()
{
    printf("Filho: Tchau pai!\n");
}

void filho_inicio()
{
    signal(SIGUSR1, filho_fim);
    printf("Filho: Oi pai!\n");
    for (;;);
}

int main()
{
    int pid;
    pid = fork();

    if (pid == 0)
        filho_inicio();
    else
    {
        sleep(1);
        printf("Pai: Oi filho!\n");
        kill(pid, SIGUSR1);
        sleep(1);
    }
    exit(0);
}