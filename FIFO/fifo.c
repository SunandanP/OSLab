#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	printf("Fifo Created for %d", mkfifo("fifo1", 0777));
}
