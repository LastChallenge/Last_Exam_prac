#include "header.h"

#define BUF_SIZE 1024 
#define SOCK_PATH "calc_socket"

typedef struct information {
	int operand;  // 앞 피연산자
	int operand2; // 뒤 피연산자
	char operator; // 연산자
	int result;
}info;

int main() {
	int s, t, len;
	struct sockaddr_un remote;
	info i;
	char str[BUF_SIZE];

	if((s = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
		printf("socket-error");
		exit(1);
	}
	printf("Trying to connect... \n");

	remote.sun_family = AF_UNIX;
	strcpy(remote.sun_path, SOCK_PATH);
	len = strlen(remote.sun_path) + sizeof(remote.sun_family);

	if(connect(s, (struct sockaddr *)&remote, len) == -1) {
		printf("connect-error");
		exit(1);
	}

	printf("Connected. \n");

	while(printf("> "), fgets(str, BUF_SIZE, stdin), !feof(stdin)) {
		i.operand = atoi(&str[0]);
		i.operator = str[1];
		i.operand2 = atoi(&str[2]);

		if(send(s, &i, sizeof(i), 0) == -1) {
			printf("send-error");
			exit(1);
		}
		if((t = recv(s, &i, 100, 0)) > 0) {
			printf("result> %d", i.result);
		} else {
			if(t < 0) {
				printf("recv-error");
				exit(1);
			} else {
				printf("server closed connection \n");
				exit(1);
			}
		}
	}
	close(s);

	return 0;
}


