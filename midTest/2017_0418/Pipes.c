#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1024

int main() {
	int n, fd[2];
	pid_t pid;
	char line[MAXLINE];
	char *buf;

	

	if(pipe(fd) < 0) {
		printf("pipe error \n");
		return 0;
	}
	if((pid = fork()) < 0) {
		printf("fork error \n");
	} else if(pid > 0) { /* parent */
		close(fd[0]);
		write(fd[1], "Hello World! \n", 14);
	} else { /* child */
		close(fd[1]);
		n = read(fd[0], line, MAXLINE);
		write(STDOUT_FILENO, line, n);
	}
	exit(EXIT_SUCCESS);
}
