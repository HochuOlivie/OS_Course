#include "main.h"

list* add(list *l, char *arr) {
    if (l == NULL) {
        l = (list*)malloc(sizeof(list));
        l->next = NULL;
        l->string = malloc(strlen(arr)*sizeof(char));
        arr[strlen(arr) - 1] = '\0';
//        memcpy(l->string, arr, sizeof(char)*strlen(arr));
//        strcpy(l->string, arr);
//        strncpy(l->string, arr, strlen(arr)*sizeof(char));
        char *k = l->string;
        for (char *i = arr; *i; i++) {
            *k++ = *i;
        }
        return l;
    }
    else {
        l->next = add(l->next, arr);
    }
    return l;
}

int main() {
    list *l = NULL;
    char arr[2097153];
    fgets(arr, 2097153, stdin);
    while (arr[0] != '.') {
        l = add(l, arr);
        fgets(arr, 2097153, stdin);
    }
    for (;l;l = l->next) {
        puts(l->string);
    }
}
