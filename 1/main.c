#include "main.h"



int main(int argc, char *argv[], char *envp[]) {
    struct rlimit lol0;
    getrlimit(RLIMIT_CORE, &lol0);
    long long coreMaxVal = lol0.rlim_max;
    
    static struct option long_options[] = {
        //        {"V",     required_argument, 0, 'V'},
        {"Unew_ulimit",  required_argument, 0, 'U'},
        {"Csize", required_argument, 0, 'C'},
        {0, 0, 0, 0}
    };
    int long_index = 0;
    char c;
    while ((c = getopt_long_only(argc, argv, "ispucdvV:", long_options, &long_index)) != EOF) {
        switch (c) {
            case 'i':
                
                printf("User real ID: %d\nUser effective ID: %d\nGroup real ID: %d\nGroup effective ID: %d\n", getuid(), geteuid(), getgid(), getegid());
                break;
            case 's':
                setpgid(getpid(), 0);
                break;
            case 'p':
                printf("Process ID: %d\nParent ID: %d\nGroup id: %d\n", getpid(), getppid(), getpgid(0));
                break;
            case 'u':
                printf("Current ulimit value: %ld\n", ulimit(UL_GETFSIZE));
                break;
            case 'U': {
                long valL = ulimit(UL_SETFSIZE, atol(optarg));
                if (valL != -1)
                    printf("New val for ulimit: %ld\n", valL);
                else
                    printf("Bad value for ulimit\n");
                break;
            }
            case 'c':
                printf("Core-file size limit: %lld\n", coreMaxVal);
                break;
            case 'C': {
                const struct rlimit lol = {atoi(optarg), coreMaxVal};
                (setrlimit(RLIMIT_CORE, &lol)+1)? printf("Changed core-file size to %d\n", atoi(optarg)): printf("Failed to change core-file size\n");
                break;
            }
            case 'd': {
                char cwd[4096];
                getcwd(cwd, sizeof(cwd));
                printf("Curr working dir: %s\n", cwd);
            }
            case 'v':
                printf("\nEnvironmental variables:\n");
                printf("-----------------------------");
                char** s;
                for (s = envp; *s; *s++) {
                    printf("\n%s\n", *s);
                }
                printf("-----------------------------\n");
                break;
            case 'V':
                putenv(optarg);
                break;
            case '?':
                printf("Invalid option\n");
        }
    }
}

