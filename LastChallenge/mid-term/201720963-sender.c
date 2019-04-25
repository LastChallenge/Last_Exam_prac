#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "201720963-receiver.c"

#define MAXLINE 1024

int main() {
	int n, fd[2];
	int input[10];
	pid_t pid;
	char line[MAXLINE];
	char *buf;

	if(pipe(fd) < 0) {
		printf("pipe error \n");
		return 0;
	}
	if((pid = fork()) < 0) {
		printf("fork error \n");
		return 0;
	} else if(pid > 0){
		close(fd[0]);
		for(int i = 0; i<9; i++) {
			input[i] = scanf("%d", &input[i]);
			write(fd[1], input[i], 14);
		}
	} else {
		close(fd[1]);
		read_receiver(*line[MAXLINE], *fd[0], MAXLINE);
	}
}


		
