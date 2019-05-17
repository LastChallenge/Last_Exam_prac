#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sigint_handler(int signo) {

	printf("받음 \n");
}

int main() {
	sigset_t sigset;

	sigfillset(&sigset);
	sigdelset(&sigset, SIGUSR1);

	printf("PID: %d, waiting for only SIGUSR1 \n", getpid());

	sigsuspend(&sigset);

	return 0;
}
