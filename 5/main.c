#include "main.h"


int main() {
    int fp;
    fp = open("input.txt", O_RDONLY);
    
    const long size = lseek(fp, 0, SEEK_END);
    lseek(fp, 0, SEEK_SET);
    
    char c;
    int ll = 0, i = 0;
    int idArr[size + 1];
    idArr[ll++] = -1;
    
    while (read(fp, &c, 1) != 0) {
        if (c == '\n')
            idArr[ll++] = i;
        i++;
    }
    
    lseek(fp, 0, SEEK_SET);
    int num; scanf("%d", &num);
    while (num != 0) {
        lseek(fp, idArr[num - 1] + 1, SEEK_SET);
        read(fp, &c, 1);
        while (c != '\n') {
            printf("%c", c);
            read(fp, &c, 1);
        }
        printf("\n");
        scanf("%d", &num);
    }
    exit(0);
}
