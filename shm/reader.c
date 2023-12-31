#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main(){
	key_t key = ftok("shmfile",65);
	
	int shmid = shmget(key,1024,0666|IPC_CREAT);
	
	char *str = (char*) shmat(shmid, (void*) 0, 0);
	
	printf("Data Read : ");
	printf("\ndata : %s", str);
	
	shmdt(str);
	
	shmctl(shmid, IPC_RMID, NULL);
}
