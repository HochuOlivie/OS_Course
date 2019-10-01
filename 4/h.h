#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct list {
    char arr[1025];
    struct list *next;
} list;
list* add(list *l, char* arr);
