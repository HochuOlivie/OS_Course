#include "h.h"

list* add(list* l, char* arr) {
    if (l == NULL) {
        l = (list*)malloc(sizeof(list));
        l->next = NULL;
        memcpy(l->arr, arr, sizeof(char)*strlen(arr));
        return l;
    }
    else {
        l->next = add(l->next, arr);
    }
    return l;
}

int main() {
    list* l = NULL;
    char arr[1025];
    gets(arr);
    while (arr[0] != '.') {
        l = add(l, arr);
        gets(arr);
    }
    for (;l;l = l->next) {
        puts(l->arr);
    }
}
