#include "shm-header.h"

int main() {
	int shm_id;
	void *shm_addr;
	struct shmid_ds shm_info;

	if(-1 == (shm_id = shmget((key_t)KEY_NUM, MEM_SIZE, IPC_CREAT | 0666))) {
		perror("shmget() error");
		return -1;
	}
	else {
		printf("shmget() success \n");
	}

	if((void *)-1 == (shm_addr = shmat(shm_id, (void *)0 , 0))) {
		perror("shmat() error");
		return -1;
	} else {
		printf("shmat() success \n");
	}

	if(-1 == shmctl(shm_id, IPC_STAT, &shm_info)) {
		perror("shmctl() error");
		return -1;
	}


	printf("공유 메모리를 사용하는 프로세스의 개수: %ld \n", shm_info.shm_nattch);
	

	if(-1 == shmdt(shm_addr)) {
		printf("공유 메모리 분리 실패 \n");
		return -1;
	}
	else {
		printf("공유 메모리 분리 성공 \n");
	}d
	
	if(-1 == shmctl(shm_id, IPC_RMID, 0)) {
		printf("공유 메모리 제거 실패 \n");
		return -1;
	}
	else {
		printf("공유 메모리 제거 성공 \n");
	}
	return 0;
}





			
