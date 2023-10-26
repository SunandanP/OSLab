#include<stdio.h>
#include<stdlib.h>

int *pages;
int pageSize;
int frameSize;
int *frame;
int *usage;

// Setting up the static inputs with 7 pages and frameSize of 3.
void getPages(){
	int *temp = malloc(sizeof(int) * 7);
	temp[0] = 1;
	temp[1] = 2;
	temp[2] = 2;
	temp[3] = 4;
	temp[4] = 1;
	temp[5] = 3;
	temp[6] = 5;
	
	frameSize = 3;
	pageSize = 7; 
	pages = temp;
}

// Initializing the frame data structure.
void initFrame(){
	frame = malloc(sizeof(int) * frameSize);
	for(int i = 0; i < frameSize; i++){
		frame[i] = -1;
	}
}

void printFrame(){
	printf("Frame => ");
	for(int i = 0; i < frameSize; i++){
		printf("%d ", frame[i]);
	}
	printf("\n");
}


// For checking if the key exist in the frame.
int checkHit(int key){
	for(int i = 0; i < frameSize; i++){
		if(key == frame[i]){
			return 1;
		}
	}
	
	return 0;
}

void beautify(){
	printf("---------------------------------------------------\n");
}

void fcfs(){
	beautify();
	printf("FCFS\n");
	beautify();

	int count = 0;
	int hit = 0;
	printFrame();
	for(int i = 0; i < pageSize; i++){
		// Page fault
		if(checkHit(pages[i]) == 0){
	
			frame[count] = pages[i];
			
			count++;
			if(count == frameSize){
				count = 0;			
			}
		}
		// Page hits
		else {
	
			hit++;
		}

		printf("Page Under Consideration : %d\n",pages[i]);
		printFrame();
	}
	
	printf("Page faults : %d", pageSize - hit);
	printf("\n");
}

void printUsage(){
	for(int i =0; i < frameSize; i++){
		printf("LRU : %d :: %d\n",i, usage[i]);
	}
}

int findLRU(){
	int min = usage[0], index;
	for(int i = 0; i < frameSize; i++){
		if(usage[i] < min){
			min = usage[i];
			index = i;
			printf("Min : %d",index);
		}
	}
	printf("\n%d\n", index);
	return index;
}

void initUsage(){
	usage = malloc(sizeof(int) * frameSize);
	
		
	// init usage array
	for(int i = 0; i < frameSize; i++){
		usage[i] = 0;
	}
	
	for(int i = 0; i < frameSize; i++){
		printf("%d", usage[i]);
	}
}

void leastRecentlyUsed(){
	beautify();
	printf("LRU\n");
	beautify();
	
	int count = 0;
	int hit = 0;
	
	printFrame();
	for(int i = 0; i < pageSize; i++){
		
		// Page fault
		if(checkHit(pages[i]) == 0){
			if(frame[count] == -1){
				frame[count] = pages[i];
			}
			else{
				printf("LRU target : %d",findLRU());
				frame[findLRU()] = pages[i];
				usage[i] = 0;
			}
			
			usage[i]++;
			count++;
			if(count == frameSize){
				count = 0;			
			}
		}
		// Page hits
		else {
			usage[i]++;
			hit++;
		}

		printf("Page Under Consideration : %d\n",pages[i]);
		printFrame();
		printUsage();
	}
	
	printf("Page faults : %d", pageSize - hit);
	printf("\n");
	
}

void runApp(){
	getPages();
	initFrame();
	fcfs();
	initFrame();
	initUsage();
	leastRecentlyUsed();
}

int main(){
	runApp();
}
