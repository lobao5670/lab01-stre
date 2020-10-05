#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
    
    pid = fork();
    
    if (pid < 0) {
        fprintf(stderr, "Fork Failed\n");
        return 1;
    } else if (pid == 0) {
        printf("I am the child %d\n", pid);
        execlp("/bin/ls", "ls", NULL);
    } else {
        printf("i am the parent %d\n", pid);
        wait(NULL);
        
        printf("Child complete\n");
    }

    return 0;
}