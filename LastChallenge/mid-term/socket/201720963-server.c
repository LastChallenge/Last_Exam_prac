#include "201720963-head.h"

typedef struct information {
	int operand;
	int operand2;
	char operator;
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
	int done, n, a;
	
	/* connection each process useing pipe */
	int fds1[2], fds2[2];
	pid_t pid;
	int buf[PIPE_SIZE];

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
		t = sizeof(remote);

		if((s2 = accept(s, (struct sockaddr *)&remote, &t)) == -1) {
			exit(1);
		}
		
		pipe(fds1), pipe(fds2);
		pid = fork();

		if(pid == 0) {
			read(fds2[0], &i, sizeof(i));
			a = calcutate(i.operator, i.operand, i.operand2);
			write(fds1[1], &a, sizeof(a));
		 } else {
			 done = 0;
			 
			do {
				n = recv(s2, &i, sizeof(i), 0);
					if(n <= 0) {
						if(n < 0) printf("recv-error");
						done = 1;
					}
					write(fds2[1], &i, sizeof(i));  //자식에게 구조체 전달
					read(fds1[0], &a, sizeof(a)); // 자식에게 연산 결과 가져옴

				if(send(s2, &a, sizeof(a), 0) < 0) {
					printf("send-error");
					done = 1;
				}
			}
			while(!done);		
			close(s2);
		}
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



	








