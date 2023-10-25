#include<stdio.h>
#include<fcntl.h>

int main(){
	int result, n;
	char buffer[100];
	result = open("fifo1", O_RDONLY);
	n =  read(result, buffer,100);
	printf("Done with reading :: PID : %d\n", getpid());
	printf("Message : %s",buffer);
}
