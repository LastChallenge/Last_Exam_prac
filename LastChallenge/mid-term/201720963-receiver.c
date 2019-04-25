#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1024

int main() {
	read_receiver(&line[MAXLINE], &fd[0], MAXLINE);

	return 0;
}

void read_receiver(char *line[MAXLINE], int *fd[0], MAXLINE) {
	int n;
	n = read(fd[0], line, MAXLINE);
	write(STDOUT_FILENO, line n);

}
