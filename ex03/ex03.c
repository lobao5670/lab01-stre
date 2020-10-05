#define _GNU_SOURCE
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
// 64kB stack
#define FIBER_STACK 1024 * 64
// The child thread will execute this function
int threadFunction(void *argument)
{
    sleep(1);
    printf("Processo filho: %d\n", getpid());
    kill(getpid(), SIGUSR1);
    printf("child thread exiting\n");
    return 0;
}
void funcaoCompartilhada() {
    printf("Sou o processo %d\n", getpid());
}
int main()
{
    void *stack;
    pid_t pid;
    
    printf("Processo pai: %d\n", getpid());
    // Allocate the stack
    stack = malloc(FIBER_STACK);
    if (stack == 0)
    {
        perror("malloc: could not allocate stack");
        exit(1);
    }
    printf("Creating child thread\n");
    // Call the clone system call to create the child thread
    pid = clone(&threadFunction, (char *)stack + FIBER_STACK,
                SIGCHLD | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, 0);

    signal(SIGUSR1, funcaoCompartilhada);

    if (pid == -1)
    {
        perror("clone");
        exit(2);
    }

    // Wait for the child thread to exit
    pid = waitpid(pid, 0, 0);
    if (pid == -1)
    {
        perror("waitpid");
        exit(3);
    }

    // Free the stack
    free(stack);
    printf("Child thread returned and stack freed.\n");
    return 0;
}