#include "msg_header.h"

#define BUFF_SIZE 1024

typedef struct {
	long data_type;
	int data_num;
	char data_buff[BUFF_SIZE];
}msg_t;

int main(int argc, char *argv[]) {
	int msgid;
	int i;
	msg_t data;
	struct msqid_ds msgstat;

	if(argc < 2) {
		perror("parameter is required");
		exit(1);
	}

	if(-1 == (msgid = msgget((key_t)1720963, IPC_CREAT | 0666))) {
		perror("msgget() error");
		exit(1);
	}

	if(-1 == msgctl(msgid, IPC_STAT, &msgstat)) {
		perror("msgctl() error");
		exit(1);
	}
	printf("# of msg in the queue: %ld \n", msgstat.msg_qnum);

	for(i = 0; i < msgstat.msg_qnum; i++) {
		if(-1 == msgrcv(msgid, &data, sizeof(msg_t) - sizeof(long), atoi(argv[1]), 0)) {
			perror("msgrcv() error");
			exit(1);
		}
		printf("%d - %s \n", data.data_num, data.data_buff);
	}

	return 0;
}
