#define _GNU_SOURCE
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
#define FIBER_STACK 1024 * 64

double resultado1 = 1;
double resultado2 = 1;
int num;

int fatorial(void* argument) {
    for (int i = 1; i <= num / 2; i++) {
        resultado1 *= i;
    }

    return 0;
}

int main()
{
    int pid;
    void *stack;
    printf("Insira um numero\n");
    scanf("%d", &num);
    
    stack = malloc(FIBER_STACK);

    pid = clone(&fatorial, (char *)stack + FIBER_STACK,
                SIGCHLD | CLONE_VM, 0);
    
    for (int i = num / 2 + 1; i <= num; i++) {
        resultado2 *= i;
    }
    
    pid = waitpid(pid, 0, 0);
    printf("Resultado 1: %f\n", resultado1);
    printf("Resultado 2: %f\n", resultado2);
    printf("Fatorial: %f\n", resultado1 * resultado2);

    return 0;
}