#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void charatatime(char *str) {
	char *ptr;
	int c; 
	setbuf(stdout, NULL);
	for(ptr = str; (c = *ptr++) != 0;) {
		putc(c, stdout);
	}

}

int main() {
	pid_t pid;

	if((pid = fork()) < 0) {
		return 0;
	} else if(pid == 0){  /*Child*/
		charatatime("output from Child \n");
	} else { /*Parent */
		charatatime("output from Parent \n");
	}
	exit(EXIT_SUCCESS);
}
