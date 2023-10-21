#include <stdio.h>
#include <stdlib.h>
// Process_wise Resources
struct Resources{
    int pid;
    int a;
    int b;
    int c;

};

// Constructor for resources
void initResources(struct Resources * inst, int pid, int a, int b, int c){
    inst->pid = pid;
    inst->a = a;
    inst->b = b;
    inst->c =c;
}

int processCount;
struct Resources *allocated;
struct Resources *max;
struct Resources *need;
struct Resources *order;
struct Resources current;

// current Initialization
void initCurrent(int a, int b, int c){
    initResources(&current,-1, a, b, c);
}

// Allocated Initialization
void initAllocated(){
    printf("Enter the number of processes : ");
    scanf("%d", &processCount);

    struct Resources * temp;
    temp = malloc((sizeof (struct Resources) * processCount));

    int a, b, c;
    printf(":: Input Module for Allocated Resources ::\n");
    for (int i = 0; i < processCount; i++) {
        printf("Process p%d",i);
        printf("Enter the value of Resource A : ");
        scanf("%d", &a);
        printf("\n");
        printf("Enter the value of Resource B : ");
        scanf("%d", &b);
        printf("\n");
        printf("Enter the value of Resource C : ");
        scanf("%d", &c);
        printf("\n");

        initResources(&temp[i], i, a, b, c);
    }

    allocated = temp;
}

// Allocated test Initialization
void initAllocatedTest(int count, int a[], int b[], int c[]){
    processCount = count;

    struct Resources * temp;
    temp = malloc((sizeof (struct Resources) * processCount));

    for (int i = 0; i < processCount; i++) {
        initResources(&temp[i], i, a[i], b[i], c[i]);
    }
    allocated = temp;

}

// Max Initialization
void initMax(){
    struct Resources * temp;
    temp = malloc((sizeof (struct Resources) * processCount));

    int a, b, c;
    printf(":: Input Module for Maximum Resources ::\n");
    for (int i = 0; i < processCount; i++) {
        printf("Process p%d\n",i);
        printf("Enter the value of Resource A : ");
        scanf("%d", &a);
        printf("\n");
        printf("Enter the value of Resource B : ");
        scanf("%d", &b);
        printf("\n");
        printf("Enter the value of Resource C : ");
        scanf("%d", &c);
        printf("\n");

        initResources(&temp[i], i, a, b, c);
    }
    max = temp;

}

// Max test Initialization
void initMaxTest(int count, int a[], int b[], int c[]){
    processCount = count;

    struct Resources * temp;
    temp = malloc((sizeof (struct Resources) * processCount));

    for (int i = 0; i < processCount; i++) {
        initResources(&temp[i], i, a[i], b[i], c[i]);
    }

    max = temp;
}

// Need calculations
void calcNeed(){
    struct Resources * temp = malloc((sizeof (struct Resources) * processCount));
    for (int i = 0; i < processCount; i++) {
        temp[i].pid = i;
        temp[i].a = max[i].a - allocated[i].a;
        temp[i].b = max[i].b - allocated[i].b;
        temp[i].c = max[i].c - allocated[i].c;
    }

    need = temp;
}

//print the table
void printMatrices(){
    printf("Allocated\t   | \t\tMax        | \t\tNeed\n");
    printf("A\tB\tC | \t");
    printf("A\tB\tC | \t");
    printf("A\tB\tC\t\n");

    for (int i = 0; i < processCount; i++) {
        printf("%d\t%d\t%d | \t",allocated[i].a,allocated[i].b,allocated[i].c);
        printf("%d\t%d\t%d | \t",max[i].a,max[i].b,max[i].c);
        printf("%d\t%d\t%d",need[i].a,need[i].b,need[i].c);
        printf("\n");
    }
}

// check if process is already scheduled
int checkScheduledStatus(int * a, int key ){
    for (int i = 0; i < processCount; i++) {
        if(a[i] == key){
            return 1;
        }
    }
    return 0;
}

// Scheduling algorithm
void bankerScheduling(){
    int scheduledCount = 0;
    int temp[processCount];

    for (int i = 0; i < processCount; i++) {
        temp[i] = -1;

    }

    for (int i = 0; i < processCount; i++) {
        printf("Process under consideration : P%d\n",i);
        printf("Values\t\tA\tB\tC\t\n");
        printf("Need\t\t");
        printf("%d\t%d\t%d\t\n",need[i].a, need[i].b, need[i].c);

        printf("Available\t");
        printf("%d\t%d\t%d\t\n",current.a, current.b, current.c);

        if(need[i].a <= current.a && need[i].b <= current.b && need[i].c <= current.c && checkScheduledStatus(
                (int *) &temp, need[i].pid) == 0){
            current.a += allocated[i].a;
            current.b += allocated[i].b;
            current.c += allocated[i].c;

            temp[scheduledCount] = need[i].pid;
            scheduledCount++;

            if(scheduledCount == processCount){
                break;
            }
        }

        if(i == processCount-1){
            i = -1;
        }
    }

    printf("Safe sequence : ");
    for (int i = 0; i < processCount; i++) {
        printf("P%d ", temp[i]);
    }

}

void runApp(int count){
    int a, b, c;
    printf("Enter the resources for currently Available resources : \n");
    printf("A :");
    scanf("%d",&a);
    printf("B :");
    scanf("%d",&b);
    printf("C :");
    scanf("%d",&c);
    initCurrent(a,b,c);

    // explicit processCount
//    processCount = count;

    // production routine
    initAllocated();
    initMax();
    // test routine

//    int aA[] = {0,2,3,2,0};
//    int aB[] = {1,0,0,1,0};
//    int aC[] = {0,0,2,1,2};
//
//    int mA[] = {7,3,9,2,4};
//    int mB[] = {5,2,0,2,3};
//    int mC[] = {3,2,2,2,3};
//
//    initAllocatedTest(processCount, aA, aB, aC);
//    initMaxTest(processCount, mA, mB, mC);

    calcNeed();
    printMatrices();
    bankerScheduling();
}

int main() {
    runApp(5);
    return 0;
}
