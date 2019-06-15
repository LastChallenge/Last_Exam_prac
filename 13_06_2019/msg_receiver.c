#include "msg_header.h"

#define BUFF_SIZE 1024

typedef struct {
	long data_type;
	int data_num;
	char data_buff[BUFF_SIZE];
}msg_t;


int main() {
	int msgid;
	msg_t data;

	if(-1 == (msgid = msgget((key_t)1720963, IPC_CREAT | 0666))) {
		perror("msgget() error");
		exit(1);
	}

	while(1) {
		if(-1 == msgrcv(msgid, &data, sizeof(msg_t) - sizeof(long), 1,0)) {
			perror("msgrcv() error");
			exit(1);
		}
		printf("%d - %s \n", data.data_num, data.data_buff);
	}
	return 0;
}

