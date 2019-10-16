#ifndef oScOdE
#define oScOdE 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
    char *string;
    struct list *next;
} list;

list* add(list *l, char *arr);

#endif
