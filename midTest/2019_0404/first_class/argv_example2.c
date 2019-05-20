#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int i;
	for(i = 0; argv[i] != NULL; i++) {
		//POSIX.1 and ISO guaranteee argv[argc] == NULL
		printf("argv[%d] = %s \n", i, argv[i]);
	}
	exit(EXIT_SUCCESS);
}
