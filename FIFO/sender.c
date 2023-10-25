#include<stdio.h>
#include<fcntl.h>



int main(){
	int result, n;
	result = open("fifo1", O_WRONLY);
	char mes[100];
	printf("Enter the message : ");
	scanf("%s",mes);
	write(result, mes, sizeof(mes));
	printf("Done sending :: PID : %d", getpid());

}
