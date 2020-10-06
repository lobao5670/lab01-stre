#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1

int main()
{
    int fd[2];
    pid_t pid;
    pipe(fd);
    pid = fork();

    if (pid > 0) {
        int n;

        close(fd[WRITE]);
        read(fd[READ], &n, sizeof(n));
        close(fd[READ]);
        
        printf("Numero recebido pelo filho: %d\n", n);
        kill(pid,SIGKILL);
        _exit(0);
    }
    if (pid == 0) {
        int n = 10;

        close(fd[READ]);
        write(fd[WRITE], &n, sizeof(n));
        close(fd[WRITE]);

        pause();
    }

}