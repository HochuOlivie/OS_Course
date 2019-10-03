#include "main.h"


void addV(Vector *v, il elem) {
    if (v->cap == 0) {
        v->data = malloc(sizeof(il));
        v->size = 1;
        v->cap = 1;
    }
    if (v->size == v->cap) {
        v->cap *= 2;
        v->data = realloc(v->data, v->cap*sizeof(il));
        v->data[v->size++] = elem;
    }
    else {
        v->data[v->size++] = elem;
    }
}

Vector v;

void writeAllFile(char* str) {
    printf("%s", str);
}

int main() {
    int fd;
    fd = open("input.txt", O_RDONLY);
    
    //    const long size = lseek(fd, 0, SEEK_END);
    //    lseek(fd, 0, SEEK_SET);
    struct stat buff;
    fstat(fd, &buff);
    
    fd_set input_set;
    struct timeval  timeout;
    int ready_for_reading = 0;
    
    FD_ZERO(&input_set);
    FD_SET(0, &input_set);
    
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;
    
    char* memFile = mmap(NULL, buff.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    
    il a0;
    a0.index = -1;
    int ll = 0;
    int i = 0;
    for (i = 0; i < buff.st_size; i++) {
        ll++;
        if (memFile[i] == '\n') {
            a0.len = ll;
            addV(&v, a0);
            a0.index = i;
            ll = 0;
        }
    }
    a0.len = ll;
    addV(&v, a0);
    
    ready_for_reading = select(fd, &input_set, NULL, NULL, &timeout);
    if (ready_for_reading) {
        int num; scanf("%d", &num);
        
        while (num != 0) {
            if (num >= v.size || num < 0) {
                fprintf(stderr, "Error: no such line\n");
                scanf("%d", &num);
                continue;
            }
            i = v.data[num].index + 1;
            while (memFile[i] != '\n') {
                printf("%c", memFile[i]);
                i++;
            }
            printf("\n");
            timeout.tv_sec = 5;
            timeout.tv_usec = 0;
            ready_for_reading = select(fd, &input_set, NULL, NULL, &timeout);
            if (ready_for_reading)
                scanf("%d", &num);
            else {
                writeAllFile(memFile);
                exit(0);
            }
        }
    }
    else {
        writeAllFile(memFile);
    }
    exit(0);
}

