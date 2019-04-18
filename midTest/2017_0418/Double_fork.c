#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	pid_t pid;

	
	if((pid = fork()) < 0) {
		printf("fork error \n");
		return 0;
	} else if(pid == 0) {
		printf("I'm 2nd pid: %d \n", getpid());

		if((pid = fork()) < 0) {
			printf("3nd fork error \n");
			return 0;
		} else if(pid == 0) {
			printf("I'm 3nd pid: %d \n", getpid());
			printf("3nd pid: My ppid is a %d \n", getppid());
			exit(0);
		}
		exit(0);
		
	} else {
		printf("I'm parend pid: %d \n", getppid());
		exit(0);
	}
	return 0;
}
