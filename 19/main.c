
#include "main.h"


int main() {

        printf("Vvedite shablon imeni faila: ");
        char pattern[1025];
        gets(pattern);
        int k = 0;
        DIR *dir;
        struct dirent *ent;
        if ((dir = opendir (".")) != NULL) {
                while ((ent = readdir (dir)) != NULL) {
                        if (!fnmatch(pattern, ent->d_name, 0)) {
                                printf("%s\n", ent->d_name);
                                k = 1;
                        }
                }

        }
        if (k == 0) {
                puts(pattern);
        }
        return 0;


}

