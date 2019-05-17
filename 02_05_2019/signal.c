#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void (*old_func)(int);

void sigint_handler(int signo) {
	printf("-Ctrl 누름 \n");
	signal(SIGINT, old_func);  //또는 signal(SIGINT, SIG_DEF);
}

int main() {
	old_func = signal(SIGINT, sigint_handler);

	while(1) {
		printf("signal handler registerd \n");
		sleep(1);
	}
	return 0;
}

