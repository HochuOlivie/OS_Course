#include "main.h"

int main(int argc, char *argv[]) {

    
    pid_t id;
    if ((id = fork()) != 0) {
	int i = 2;
	for (i; i < argc; i++)
		system(argv[i]);
        int status;
        wait(&status);
        printf("Child exit status: %d\n", WEXITSTATUS(status));
    }
    else {
        system(argv[1]);
    }
    return 13;
}

