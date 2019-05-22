#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void){
	pid_t pid;
	int status;
	
	if((pid = fork()) < 0) {
		printf("fork error \n");
	}
	else if(pid == 0) {
		printf("hi from child PID:%d\n", getppid());

		sleep(100 * 1000);

		exit(7);
	}
	else {
		if(wait(&status) != pid) {
			printf("wait error \n");
		}
		printf("hi from parent \n");
			if(WIFEXITED(status)) {  
				printf("normal termination, exit status = %d \n",
					WEXITSTATUS(status));
			}
			else if(WIFSIGNALED(status)) {
				printf("abnormal termination, signal number = %d \n",
					WTERMSIG(status));
			}
	}
	exit(0);
}
