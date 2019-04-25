#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int n = 1;

int main() {
	pid_t pid;


	if ((pid = fork()) <0) {
		printf("fork error \n");
		return 0;
	} else if(pid == 0) {
		for(int i =1; i<9; i++) {
			for(int i =0; i<99; i++) {
				n++;
			}
		}

	} else {
		printf("parent_n: %d \n", n);
		exit(0);
	}



