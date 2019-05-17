#include "client1.h"

#define SOCK_PATH "echo_socket"

struct TLV {
	int type;
	int size;
	int calc[2];
}TLV;

int main(void) {
	int s, t, len;
	struct sockaddr_un remote;
	char str[100];

	if((s = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	printf("Trying to connect... \n");

	remote.sun_family = AF_UNIX;
	strcpy(remote.sun_path, SOCK_PATH);
	len = strlen(remote.sun_path) + sizeof(remote.sun_family);

	if(connect(s, (struct sockaddr *)&remote, len) == -1) {
		perror("connect");
		exit(1);
	}

	printf("Connected. \n");

	while(printf("> "), fgets(str, sizeof(str), stdin), !feof(stdin)) {
		
		if(send(s, &str, sizeof(TLV), 0) == -1) {
			perror("send");
			exit(1);
		}
		if((t = recv(s, &TLV, sizeof(TLV), 0)) > 0) {
			TLV.type = 1;
			TLV.calc[0] = 99;
			TLV.calc[1] = 99;
			
			if(TLV.type == 1) {
				return printf("calc> %d", TLV.calc[0] + TLV.calc[1]);
			}
		} else {
			if(t < 0) perror("recv");
			else printf("Server closed connection \n");
			exit(1);
		}
	}

	close(s);
	
	return 0;
}
