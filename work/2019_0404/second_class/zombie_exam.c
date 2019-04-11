#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
	pid_t pid;
	int i;

	for(i = 0; i<5; i++) {
		if((pid = fork()) < 0) {
			printf("fork_error \n");
		} else if(pid == 0) {
			printf("bye from child %d: %d \n", i, getpid());
			exit(0);
		}
		/* parent does nothing */
	}
	sleep(100); /* time window to observe zombie */
	//100 sec
	printf("bye from parent \n");
	exit(0);
}
