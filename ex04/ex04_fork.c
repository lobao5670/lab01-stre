#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1
int num;

int main()
{
    printf("Insira um numero\n");
    scanf("%d", &num);

    int fd[2];
    pid_t pid;
    pipe(fd);
    pid = fork();

    if (pid > 0)
    {
        double n;
        double n2 = 1;
        for (int i = num / 2 + 1; i <= num; i++)
        {
            n2 *= i;
        }
        close(fd[WRITE]);
        read(fd[READ], &n, sizeof(n));
        close(fd[READ]);
        printf("Resultado 1: %f\n", n);
        printf("Resultado 2: %f\n", n2);
        printf("Fatorial: %f\n", n * n2);
        kill(pid, SIGKILL);
        _exit(0);
    }
    if (pid == 0)
    {
        double n = 1;
        for (int i = 1; i <= num / 2; i++)
        {
            n *= i;
        }

        close(fd[READ]);
        write(fd[WRITE], &n, sizeof(n));
        close(fd[WRITE]);
        pause();
    }
}