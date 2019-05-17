#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
	sigset_t sigset;

	sigemptyset(&sigset); // 모든 시그널을 비우는 함수
	sigaddset(&sigset, SIGINT); // 시그널 추가
	
	printf("PID: %d, waiting for any signal except SIGINT \n", getpid());

	sigsuspend(&sigset);

	return 0;
}
