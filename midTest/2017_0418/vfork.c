#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int glob = 6;

int main() {
	int var; /* automic variable */
	pid_t pid;
	var = 88;

	printf("before vfork \n");

	if((pid = fork()) < 0) {
		return 0;
	} else if(pid == 0) {
		glob++;
		var++;
		_exit(0);
	}
	printf("pid = %d, glob = %d, var = %d \n", getpid(), glob, var);
	exit(EXIT_SUCCESS);
}


