#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char buf[] = "wirte to stdout \n";

int main() {
	pid_t pid;
	
	//write() is a system call provided by OS
	if(write(STDOUT_FILENO, buf, strlen(buf)) != strlen(buf)) {
		printf("write error \n");
	}
	//printf() is provided from glibc
	//buffer is used for various reasons
	printf("printf by %d: before fork \n", getpid());
	if((pid = fork()) < 0) {
		printf("fork error \n");
	}else if(pid == 0) {
		printf("printf by %d: hi from child! \n", getpid());
	} else {
		printf("printf by %d: hi from parent \n", getpid());
	}
	printf("printf by %d: bye \n", getpid());
	exit(0);
}
