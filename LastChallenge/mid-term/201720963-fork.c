#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	pid_t pid;
	FILE *file = fopen("file.txt", "w");

	if((pid = fork()) < 0) {
		printf("error \n");
	} else if(pid == 0) {
		putc("201720963", file);
		putc("yooyoungwoo", file);
	} else {
		getc(file);
		fclose(file);

	}
	return 0;
}


