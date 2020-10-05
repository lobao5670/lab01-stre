#include <stdio.h>

int main() {
    printf("%d\n", getpid());
    fork();
    printf("Fork 1: %d\n", getpid());
    
    fork();
    printf("Fork 2: %d\n", getpid());
    
    fork();
    printf("Fork 3: %d\n", getpid());

    return 0;
}