#include "msg_header.h"


#define BUFF_SIZE 1024

typedef struct {
	long data_type;
	int data_num;
	char data_buff[BUFF_SIZE];
}msg_t;

int main() {
	int msgid_q1;
	int msgid_q2;
	int ndx = 0;
	msg_t data;
	struct msqid_ds msgstat;


	if(-1 == (msgid_q1 = msgget((key_t)1, IPC_CREAT | 0666))) {
		perror("msgget()_q1 error");
		exit(1);
	}
	if(-1 == (msgid_q2 = msgget((key_t)2, IPC_CREAT | 0666))) {
		perror("msgget()_q2 error");
		exit(1);
	}

	if(-1 == msgctl(msgid, IPC_STAT, &msgstat)) {
		perror("msgctl() error");
		exit(1);
	}

	while(1) {
		data.data_type = (ndx++ % 3) + 1;
		data.data_num = ndx;

		sprintf(data.data_buff, "type=%ld, ndx=%d", data.data_type, ndx);

		if(-1 == (msgsnd(msgid_q1, &data, sizeof(msg_t) - sizeof(long), 0))) {
			perror("msgsnd() error");
			exit(1);
		}
		if(-1 == (msgsnd(msgid_q2, &data, sizeof(msg_t) - sizeof(long), 0))) {
			perror("msgsnd() error");
			exit(1);
		}
		sleep(1);
	}
	return 0;
}
