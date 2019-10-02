#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
typedef struct il {
    int index;
    int len;
} il;
typedef struct Vector {
    il* data;
    int cap;
    int size;
} Vector;
void addV(Vector *v, il elem);
