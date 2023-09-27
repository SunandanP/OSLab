#include<stdio.h>
#include<stdlib.h>
#define Max 100

// 1 3 0 3 5 6 3  

void printArray(int *array, int size, char* s, int num){
	printf("[ %d ] \t", num);
	for(int i = 0; i < size; i++){
		printf("%d \t" ,array[i]);
	}
	printf("\t%s \n", s);
}


int checkHit(int num, int capacity, int *array){
	for(int i = 0; i < capacity; i++){
		if(num == array[i]){
			return 1;
		}	
	}
	return 0;	
}

void FCFS(int pageSlots, int* array, int arraySize) {
	int* slots = malloc(sizeof(int) * pageSlots);
	
	//initialization
	for(int i = 0; i < pageSlots; i++){
		slots[i] = -1;	
	}
	
	printArray(slots, pageSlots, "Initialized", -1);
	
	int hit = 0, miss = 0, curr = 0;
	for(int i = 0; i < arraySize; i++){
		if(checkHit(array[i], pageSlots, slots) == 0){
			slots[curr] = array[i];
			curr++;
			curr = curr % pageSlots;
			miss++;
			printArray(slots, pageSlots, "Miss", array[i]);
		}
		else {
			hit++;
			printArray(slots, pageSlots, "Hit", array[i]);
		}
			
			
	}
	
	printf("Miss : %d \n", miss);
	printf("Hits : %d \n", hit);	
		
	
	
}

void optimal(){
}

int main(){
	int array[] = {7,0,1,2,0,3,0,4,2,3,0,3,2};
	FCFS(3, array,13);
	return 0;
}
