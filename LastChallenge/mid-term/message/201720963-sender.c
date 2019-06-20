#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define BUFF_SIZE 1024

typedef struct {
	long data_type;
	int data_num;
	char data_buff[BUFF_SIZE];
}msg_t;

int main() {
	int msqid1;
	int msqid2;
	int ndx = 1;
	int recv_num =1;
	int recv2_num =1;
	msg_t data;

	if(-1 == (msqid1 = msgget((key_t)1, IPC_CREAT | 0666))){
		perror("error");
		exit(1);
	}
	if(-1 == (msqid2 = msgget((key_t)2, IPC_CREAT | 0666))) {
		exit(1);
	}

	while(1) {
		data.data_type = ndx;
		data.data_num = recv_num++;

		sprintf(data.data_buff, "sender: type = %ld, recv_num = %d", data.data_type, recv_num);

		if(-1 == msgsnd(msqid1, &data, sizeof(msg_t) - sizeof(long), 0)) {
			exit(1);
		}
		data.data_num = ((recv2_num++) * 2);
		sprintf(data.data_buff, "sender: type = %ld, recv_num = %d", data.data_type, recv2_num);
		if(-1 == msgsnd(msqid2, &data, sizeof(msg_t) - sizeof(long), 0)) {
			exit(1);
		}
		sleep(1);
	}
	return 0;
}


