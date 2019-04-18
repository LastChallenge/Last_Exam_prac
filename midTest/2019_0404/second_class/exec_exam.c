#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

char *env_init[] = { "USER=unknown", "TERM=xterm", NULL };

int main() {
	pid_t pid;
	if((pid = fork()) < 0) {
		printf("fork error \n");
	} else if(pid == 0) {
		if(execle("/tmp/echoall", " echoall", "foo", "BAR", NULL,
					env_init) < 0) {
			printf("execle error \n");
		}
	}
	if(wait(NULL) < 0) {
		printf("wait error \n");
	}
	if((pid = fork()) < 0) {
		printf("fork error \n");
	} else if(pid == 0) {
		if(execlp("echoall",
					"echoall", "only 1 arg", NULL) < 0) {
			printf("execlp error \n");
		}
	}
	exit(0);
}
