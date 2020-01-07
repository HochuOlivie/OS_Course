#include "main.h"


void addV(Vector *v, il elem) {
    if (v->cap == 0) {
        v->data = malloc(sizeof(il));
        v->size = 1;
        v->cap = 1;
    }
    if (v->size == v->cap) {
        v->cap *= 2;
        v->data = realloc(v->data, v->cap * sizeof(il));
        v->data[v->size++] = elem;
    }
    else {
        v->data[v->size++] = elem;
    }
}

Vector v;

void writeAllFile(int fd, int strLen, char *str) {
    int i;
    for (i = 0; i < v.size; i++) {
        lseek(fd, v.data[i].index + 1, SEEK_SET);
        if (strLen < v.data[i].len) {
            str = realloc(str, v.data[i].len);
            strLen = v.data[i].len;
        }
        read(fd, str, v.data[i].len);
        fwrite(str, 1, v.data[i].len, stdout);
    }
}

int main() {
    int fd;
    fd = open("input.txt", O_RDONLY);
    
    //    const long size = lseek(fd, 0, SEEK_END);
    //    lseek(fd, 0, SEEK_SET);
    
    
    fd_set input_set;
    struct timeval  timeout;
    int ready_for_reading = 0;
    
    FD_ZERO(&input_set );
    FD_SET(0, &input_set);
    
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;
    
    
    char c;
    int i = 0;
    il a0;
    a0.index = -1;
    int ll = 0;
    while (read(fd, &c, 1) != 0) {
        ll++;
        if (c == '\n') {
            a0.len = ll;
            addV(&v, a0);
            a0.index = i;
            ll = 0;
        }
        i++;
    }
    a0.len = ll;
    addV(&v, a0);
    
    lseek(fd, 0, SEEK_SET);
    
    char* str = malloc(1);
    int strLen = 1;
    
    ready_for_reading = select(fd, &input_set, NULL, NULL, &timeout);
    if (ready_for_reading) {
        char *loll = malloc(200);
        gets(loll);
        while (1) {
            if (loll[0] == '0' && (loll[1] == '\0' || loll[1] == '\n' || loll[1] == '\r'))
                exit(0);
            int num = atoi(loll);
            if (num == 0) {
                printf("Error: Invalid Syntax\n");
                timeout.tv_sec = 5;
                timeout.tv_usec = 0;
                ready_for_reading = select(fd, &input_set, NULL, NULL, &timeout);
                if (ready_for_reading) {
                    memset(loll, '\0', 200);
                    gets(loll);
                    continue;
                }
            
                else {
                    writeAllFile(fd, strLen, str);
                    exit(0);
                }
            }
            
            if (num >= v.size - 1 || num < 0) {
                fprintf(stderr, "Error: no such line\n");
                memset(loll, '\0', 200);
                gets(loll);
		continue;
            }
            lseek(fd, v.data[num].index + 1, SEEK_SET);
            if (strLen < v.data[num].len) {
                str = realloc(str, v.data[num].len);
                strLen = v.data[num].len;
            }

            read(fd, str, v.data[num].len);
            fwrite(str, 1, v.data[num].len - 1, stdout);
            printf("% d\n", v.data[num].len - 1);
            timeout.tv_sec = 5;
            timeout.tv_usec = 0;
            ready_for_reading = select(fd, &input_set, NULL, NULL, &timeout);
            if (ready_for_reading) {
                 memset(loll, '\0', 200);
                 gets(loll);
            }
            else {
                writeAllFile(fd, strLen, str);
                exit(0);
            }
        }
    }
    else {
        writeAllFile(fd, strLen, str);
    }
    exit(0);
}

