#include "msg_header.h"

#define BUFF_SIZE 1024

typedef struct {
	long data_type;
	int data_num;
	char data_buff[BUFF_SIZE];
}msg_t;


int main(int argc, char *argv[]) {
	int msgid;
	msg_t data;

	if(-1 == (msgid = msgget((key_t)2, IPC_CREAT | 0666))) {
		perror("msgget()_q2 error");
		exit(1);
	}

	printf("Q2 receiver \n");
	while(1) {
		if(-1 == msgrcv(msgid, &data, sizeof(msg_t) - sizeof(long), atoi(argv[1]),0)) {
			perror("msgrcv() error");
			exit(1);
		}
		printf("%d - %s \n", data.data_num, data.data_buff);
	}
	return 0;
}
