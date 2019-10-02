#include "main.h"

extern char *tzname[];

int main(int argc, char* argv[], char* envp[]) {
    
    putenv("TZ=PST8PDT");
    
    time_t now;
    struct tm *sp;
    (void)time(&now);
    printf("%s", ctime(&now));
    sp = localtime(&now);
    
    printf("%d/%d/%02d %d:%02d %s\n",
           sp->tm_mday, sp->tm_mon + 1,
           sp->tm_year, sp->tm_hour,
           sp->tm_min, tzname[sp->tm_isdst]);
    exit(0);
}


