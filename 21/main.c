
#include "main.h"



#define SIGHUP  1   /* Hangup the process */ 
#define SIGINT  2   /* Interrupt the process */ 
#define SIGQUIT 3   /* Quit the process */ 
#define SIGILL  4   /* Illegal instruction. */ 
#define SIGTRAP 5   /* Trace trap. */ 
#define SIGABRT 6   /* Abort. */

int count = 0;

void handle_sigint() {
	printf("\a\n");
	count++;
}
void handle_sigquit() {
	printf("%d\n", count);
        exit(0);

}
void handle_sigalarm() {
	alarm(5);
	printf("Signal ot programmy: NADO VVODIT' ^C");
	handle_sigint();

}
void main() {
	signal(SIGALRM, handle_sigalarm);
        signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	alarm(5);
	while (1) {

	}
}



