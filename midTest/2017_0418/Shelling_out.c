#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
	char cmd[1024];
	char tmp[] = "/tmp/shellout.XXXXXX";
	int fd, status;
	FILE *File = NULL; 
	FILE *File2 = NULL;
	pid_t pid;
		
	File = fopen("C:\\newTest.txt", "w");

	if((fd = mkstemp(tmp)) == -1) {
		exit(0);
	}
	if(write(fd, 

	if((pid = fork()) < 0) {
		printf("fork_error \n");
	}
	else if(pid == 0) { /*child*/
		if(File != NULL) {
			File2 = fopen("C

	} else { /*parent*/

	}
	if(File != NULL) { 
		

	} else {


	}
}
