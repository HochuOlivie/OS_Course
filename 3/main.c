#include "main.h"

void show_id() {
    printf("Real User ID: %d\n", getuid());
    printf("Effective User ID: %d\n", geteuid());
}

void open_file(const char* name) {
    FILE* f = NULL;
    
    if(f = fopen(name, "r")) {
        printf("File opened!\n");
        fclose(f);
    }
    else {
        perror("Could not open file");
    }
}


int main() {
	show_id();
	open_file("input.txt");

	setuid(geteuid());

	show_id();
	open_file("input.txt");

	return 0;
}
