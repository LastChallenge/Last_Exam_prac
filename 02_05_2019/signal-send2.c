#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]) {

	if(argc < 3) {
		printf("사용법: ./signal-send [SIGNAL NUM] [프로세스 ID] \n");
	} else {
		kill(atoi(argv[2]), atoi(argv[1]));
	}
	return 0;
}
