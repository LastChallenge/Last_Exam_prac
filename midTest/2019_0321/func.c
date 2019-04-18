#include <stdio.h>

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
	return 0;
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
