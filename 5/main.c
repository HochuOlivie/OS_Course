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

int main() {
    int fp;
    fp = open("input.txt", O_RDONLY);
    
    //    const long size = lseek(fp, 0, SEEK_END);
    //    lseek(fp, 0, SEEK_SET);
    
    char c;
    int i = 0;
    il a0;
    a0.index = -1;
    int ll = 0;
    while (read(fp, &c, 1) != 0) {
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
    
    lseek(fp, 0, SEEK_SET);
    
    char* str = malloc(1);
    int strLen = 1;
    
    int num; scanf("%d", &num);

    while (num != 0) {
        if (num >= v.size || num < 0) {
            fprintf(stderr, "Error: no such line\n");
            scanf("%d", &num);
            continue;
        }
        lseek(fp, v.data[num].index + 1, SEEK_SET);
        if (strLen < v.data[num].len) {
            str = realloc(str, v.data[num].len);
            strLen = v.data[num].len;
        }
        read(fp, str, v.data[num].len);
        fwrite(str, 1, v.data[num].len, stdout);
        scanf("%d", &num);
    }
    exit(0);
}
