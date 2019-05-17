#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	double i;
	double j;
	char *bug = malloc(sizeof(char)); 

	for(i = 0; i<5; i++) {
		printf("loop %d ", (int)i);
		j = i/2 + i;
		printf("\tj is %lf \n", j);
	}
	strcpy(bug, "hello");
	printf("bug is %s \n", bug);

	return 0;
}
