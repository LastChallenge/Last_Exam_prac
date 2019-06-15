#include "shm-header.h"

int main() {
	int shm_id;
	void *shm_addr;

	if(-1 == (shm_id = shmget((key_t)KEY_NUM, MEM_SIZE, IPC_CREAT | 0666))) {
		perror("shmget() error");
		return -1;
	}

	if((void *)-1 == (shm_addr = shmat(shm_id, (void *)0 , 0))) {
		perror("shmat() error");
		return -1;
	}
	
	while(1) {
		printf("%s \n", (char *)shm_addr);

		sleep(1);
	}
	return 0;
}
