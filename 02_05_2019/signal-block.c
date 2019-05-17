#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signo) {
	int ndx;

	printf("-CTRL 키 누름 \n");
	printf("10초 대기 CTRL-Z 클릭 \n");

	for(ndx = 10; 0 < ndx; ndx--) {
		printf("%d 초 남았습니다 \n", ndx);
		sleep(1);
	}
}

int main() {
	struct sigaction act;

	act.sa_handler = sigint_handler; //시그널 핸들러 지정
	sigfillset(&act.sa_mask);  //모든 시그널 지정

	sigaction(SIGINT, &act, NULL);

	while(1) {
		printf("signal handler registered for SIGINT \n");
		sleep(1);
	}
	return 0;
}
