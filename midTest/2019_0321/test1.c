#include <stdio.h>
#include <stdlib.h>

int func(char oper, double a, double b);
int add(double a, double b);
int min(double a, double b);
int mul(double a, double b);
int divi(double a, double b);

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

int func(char oper, double a, double b){
	int index;
	switch(oper) {
		case '+':
			index = add(a,b);
			return index;
			break;
		case '-':
			index = min(a,b);
			return index;
			break;
		case '*':
			index = mul(a,b);
			return index;
			break;
		case '/':
			index = divi(a,b);
			return index;
			break;
	}
}
int add(double a, double b) {
	int returnNum = a+b;
	return returnNum;
}
int min(double a, double b) {
	int returnNum = a-b;
	return returnNum;
}
int mul(double a, double b) {
	int returnNum = a*b;
	return returnNum;
}
int divi(double a, double b){
	int returnNum = a/b;
	return returnNum;
}
