#include <stdio.h>
#include "calc.h" 

int main(void) {
	double a;
	double b;
	char oper;
	double returnNum;

	printf("operater: ");
	scanf("%c", &oper);

	printf("first num: ");
	scanf("%lf", &a);

	printf("second num: ");
	scanf("%lf", &b);

	returnNum = func(oper, a, b);

	printf("%lf \n", returnNum);

	return 0;
}
