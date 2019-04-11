#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int glob = 42;    /* initialized data */

int main() {
	int var;     /*automatic variable */
	pid_t pid;
	var = 88;

	if((pid = fork()) < 0) {
		printf("fork error \n");
	}else if(pid ==0) {
		printf("child pid: %d \n", getpid());
		glob++; /*modify variables */
		var++;
	} else {
		printf("parent pid: %d \n", getpid());
		sleep(1);
	}
	printf("pid = %d, glob = %d, var = %d \n", getpid(), glob, var);
	exit(0);
}
	

