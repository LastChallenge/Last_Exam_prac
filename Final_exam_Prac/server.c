#include "header.h"

#define SOCK_PATH "calc_socket"

typedef struct information {
	int operand;  //앞 피연산자
	int operand2; //뒤 피연산자
	char operator; // 연산자
	int result;
}info;


int calculate(char operator, int operand, int operand2);

int main() {
	int s, s2, len;
	unsigned int t;
	info i;
	i.operand = 0;
	i.operand2 = 0;
	struct sockaddr_un local, remote;
	pid_t pid;
	

	if((s = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
		printf("socket_error");
		exit(1);
	}
	local.sun_family = AF_UNIX;
	strcpy(local.sun_path, SOCK_PATH);
	unlink(local.sun_path);
	len = strlen(local.sun_path) + sizeof(local.sun_family);

	if(bind(s, (struct sockaddr *)&local, len) == -1) {
		printf("bind error");
		exit(1);
	}
	
	if(listen(s, 5) == -1) {
		printf("socket-full");
		exit(1);
	}

	while(1) {
		int done, n;
		printf("Waiting for a connection... \n");
		t = sizeof(remote);

		if((s2 = accept(s, (struct sockaddr *)&remote, &t)) == -1) {
			printf("accept-error");
			exit(1);
		}

		printf("connected. \n");

		if((pid = fork()) < 0) {
			printf("fork-error");
			exit(1);
		} else if(pid == 0) { //자식 
			printf("자식 프로세스 확인 PPID:%d \n", getppid());
			n = recv(s2, &i, sizeof(i), 0);
			i.result =  calculate(i.operator, i.operand, i.operand2);
		} else {
			continue;
		}

		done = 0;

		do {
			//n = recv(s2, &i, sizeof(i), 0);
			if(n <= 0) {
				if(n < 0) printf("recv-error");
				done = 1;
			}

			if(send(s2, &i, sizeof(i), 0) < 0) {
				printf("send-error");
				done = 1;
			}
		}
		while(!done);

		close(s2);
	}
}
int calculate(char operator, int operand, int operand2) {
	int result = 0;
	switch(operator) {
		case '+':
			result = operand + operand2;
			break;
		case '-':	
			result = operand - operand2;
			break;
		case '*':
			result = operand * operand2;
			break;
		case '/':
			result = operand / operand2;
			break;
	}
	return result;
}

			

	



