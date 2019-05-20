#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void) {
	pid_t pid;

	printf("before fork (%d) \n", getpid()); 

	if((pid = fork()) < 0) {
		printf("fork_error \n");
	} else if(pid == 0) {
		printf("hi from child! (%d -> %d) \n", getpid(), getppid());
		printf("hi from child! myppid %d \n", getppid());
	} else {
		// wait(NULL) // waiting until the child is dead
		printf("hi from parent! (%d) \n", getpid());
		printf("hi from parent! ppid %d \n", getppid());
	}
	printf("bye (%d) \n", getpid());
	exit(EXIT_SUCCESS);
}
