#include "main.h"

int main() {

    
    pid_t id;
    if ((id = fork()) != 0) {
        printf("Parent output: YAROBOTDOLINA\n");
        int status;
        
        wait(&status);
        printf("Child exit status: %d\n", WEXITSTATUS(status));
        printf("Second parent output: YAROBOTDOLINA\n");
    }
    else {
        system("cat main.c");
    }
    return 13;
}

