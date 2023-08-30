#include<stdlib.h>
#include<stdio.h>


struct Process{
	int pid;
	int burst;
	int arrival;
	int remaining;
	
	
};

struct Process createProcess(int pid, int b, int a){
		struct Process p;
		p.pid = pid;
		p.burst = b;
		p.arrival = a;
		p.remaining = b;
	}

void sortProcesses(struct Process processes[], int number, Process proc[]){
	
	struct Process temp;
	
	for(int i = 0; i < number; i++){
		for(int j = 0; j < number; j++){
				if(processes[j].remaining > processes[j+1].remaining){
					temp = processes[j];
					processes[j] = processes[j+1];
					processes[j+1] = temp;
				}
			} 
		}
	}
	
	struct Process proc[number];
	
	for(int i=0; i < number; i++){
		proc[i] = processes[i];
	}
	
	
	return proc;
}

int totalTimeRequired(Process processes[], int number){
	int totalSum = 0;
	for(int i = 0; i < number; i++){
		totalSum += processes[i].burst;
	}
	
	return totalSum;
}

int currentExecutable(struct Process processes[], int number, int time){
	int min = 999999;
	int pos = -1, x = (time+1 <= number) ? time+1 : number;
	
	Process proc[x];
	
		
	int current = 0;
	for(int i = 0; i < number; i++){
		if(processes[i].arrival <= time){
			proc[current++] = process[i];
		}
	}
	
	for(int i = 0; i < time+1; i++){
		if(proc[i].remaining < min){
			min = proc[i].remaining;
			pos = proc[i].pid;
		}
	}
	
	return pos;
}

int pidToPos(struct Process processes[], int number, int pid){
	for(int i = 0; i < number; i++){
		if(processes[i].pid == pid){
			return i;
		}
	}
}

void timeZone(Process arrivalBased[], int number){
		int timeRequired = totalTimeRequired(arrivalBased, number);
		int currentlyServed = -1;
		
		
		//time quantam
		for(int i = 0; i < timeRequired; i++){
			currentlyServed = pidToPos(arrivalBased, number, currentExecutable(arrivalBased, number, i));
			arrivalBased[currentlyServed].remaining--;
			printf("Time : %d | Process : %d | Burst : %d | Remaining : %d", i, arrivalBased[i].pid, arrivalBased[i].burst, arrivalBased[i].remaining);
		}
}

void shortestJobFirst(struct Process processes[], int number){
	Process arrivalBasedProcessses[number];
	
	arrivalBasedProcessses = sortProcesses(processes, number,1);
	
	//preemptive approach
	timeZone(arrivalBasedProcessses, number);
	
}

int main(){

}


/*
if(i < number && arrivalBased[i].arrival == i){
				if(currentlyServed == -1){ 
					currentlyServed = i;
					arrivalBased[i].remaining--;
					printf("Time : %d | Process : %d | Burst : %d | Remaining : %d", i, arrivalBased[i].pid, arrivalBased[i].burst, arrivalBased[i].remaining);
				}
				else{
					for(int j = 0; j < i; j++){
						if(arrivalBased[j].burst < arrivalBased[currentlyServed].burst){
							currentlyServed = j;
							arrivalBased[j].remaining--;
							printf("Time : %d | Process : %d | Burst : %d | Remaining : %d", i, arrivalBased[i].pid, arrivalBased[i].burst, arrivalBased[i].remaining);
						}
						printf("Time : %d | Process : %d | Burst : %d | Remaining : %d", i, arrivalBased[i].pid, arrivalBased[i].burst, arrivalBased[i].remaining);
						arrivalBased[currentlyServed].remaining--;
					}
				}
			}
*/
