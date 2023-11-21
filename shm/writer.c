#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main(){
	key_t key = ftok("shmfile",65);
	
	int shmid = shmget(key,1024,0666|IPC_CREAT);
	
	char *str = (char*) shmat(shmid, (void*) 0, 0);
	
	printf("Data to be written : ");
	gets(str);
	
	printf("\ndata : %s", str);
	
	shmdt(str);
}
