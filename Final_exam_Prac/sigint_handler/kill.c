// 프로세스를 죽이는 코드

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


int main(int argc, char *argv[]){ 
	if(argc < 2) {
		printf("사용법: ./signal-send [프로세스 ID] \n");
	} else {
		kill(atoi(&argv[1]), SIGKILL);
	}
	return 0;
}
