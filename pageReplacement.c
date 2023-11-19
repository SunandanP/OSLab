#include <stdio.h>
#include <stdlib.h>

int *pages;
int *frames;
int pageSize;
int frameSize;


void initPages(){
    pageSize = 14;
    int *temp = malloc(sizeof(int) * pageSize);
    int temp2[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};
    for(int i = 0; i < pageSize; i++){
        temp[i] = temp2[i];
    }

    pages = temp;

    frameSize = 4;
    temp = malloc(sizeof(int) * frameSize);
    for (int i = 0; i < frameSize; i++) {
        temp[i] = -1;
    }
    frames = temp;
}

void initPagesInput(){
    printf("Enter the size of the page reference string : ");
    scanf("%d",&pageSize);
    int *temp = malloc(sizeof(int) * pageSize);
    printf("Enter the size of the frame : ");

    scanf("%d",&frameSize);
    int *temp2 = malloc(sizeof(int) * frameSize);
    // frame initialization
    for(int i = 0; i < frameSize; i++){
        temp2[i] = -1;
    }

    // pages initiation
    for(int i = 0; i < pageSize; i++){
        printf("Enter the %dth page ", i+1);
        scanf("%d", &temp[i]);
    }

    pages = temp2;
    frames = temp;
}

// ------------------------------------ Optimal ----------------------------------------

int getMax(int arr[]){
    int max = -1, index;
    for (int i = 0; i < frameSize; i++) {
        if(arr[i] > max){
            max = arr[i];
            index = i;
        }
    }

    return index;
}

// starting from current index look for
// future pages and find where the page provided as argument is present
int findInPages(int page, int curr){
    for (int i = curr; i < pageSize; i++) {
        if(page == pages[i]){
            return i;
        }
    }

    return -1;
}

int getLastOccured(int currIndex){
    int lasts[frameSize];
    for (int i = 0; i < frameSize; i++) {
        lasts[i] = -1;
    }
    for (int i = 0; i < frameSize; i++) {
        lasts[i] = findInPages(frames[i], currIndex);
    }

    for (int i = 0; i < frameSize; i++) {
        if(lasts[i] == -1){
            return i;
        }
    }
    return getMax(lasts);
}

void print(int i, int hit , int miss, int page) {
    i++;
    printf("-------------------------------------\n");
    printf("i = %d, miss = %d, hit = %d, page = %d\n", i, miss, hit,page);
    printf("frame : ");
    for (int i = 0; i < frameSize; i++) {
        printf("%d ", frames[i]);
    }
    printf("\n-------------------------------------\n");

    printf("\n");
}

int checkHit(int page){
    for (int i = 0; i < frameSize; i++) {
        if(frames[i] == page){
            return i;
        }
    }
    return -1;
}

void optimalPageReplacement(){
    int count = 0, hit = 0, miss = 0;
    for (int i = 0; i < pageSize; i++) {
        // if any spaces are empty
        if(frames[count] == -1){
            frames[count] = pages[i];
            miss++;
            count++;
        }
        // if page already exists
        else if (checkHit(pages[i]) > -1){
            hit++;
        }
        // page fault
        else{
            frames[getLastOccured(i)] = pages[i];
            miss++;
        }

        print(i, hit, miss, pages[i]);
    }
}

void runAppOptimal(){
    initPages();
    optimalPageReplacement();
}
// -------------------------------------- OP ---------------------------------------------

/*
 * geeks for geeks example
 {7,0,1,2,0,3,0,4,2,3,0,3,2,3} frame size = 4
 -------------------------------------
i = 1, miss = 1, hit = 0, page = 7
frame : 7 -1 -1 -1
-------------------------------------

-------------------------------------
i = 2, miss = 2, hit = 0, page = 0
frame : 7 0 -1 -1
-------------------------------------

-------------------------------------
i = 3, miss = 3, hit = 0, page = 1
frame : 7 0 1 -1
-------------------------------------

-------------------------------------
i = 4, miss = 4, hit = 0, page = 2
frame : 7 0 1 2
-------------------------------------

-------------------------------------
i = 5, miss = 4, hit = 1, page = 0
frame : 7 0 1 2
-------------------------------------

-------------------------------------
i = 6, miss = 5, hit = 1, page = 3
frame : 3 0 1 2
-------------------------------------

-------------------------------------
i = 7, miss = 5, hit = 2, page = 0
frame : 3 0 1 2
-------------------------------------

-------------------------------------
i = 8, miss = 6, hit = 2, page = 4
frame : 3 0 4 2
-------------------------------------

-------------------------------------
i = 9, miss = 6, hit = 3, page = 2
frame : 3 0 4 2
-------------------------------------

-------------------------------------
i = 10, miss = 6, hit = 4, page = 3
frame : 3 0 4 2
-------------------------------------

-------------------------------------
i = 11, miss = 6, hit = 5, page = 0
frame : 3 0 4 2
-------------------------------------

-------------------------------------
i = 12, miss = 6, hit = 6, page = 3
frame : 3 0 4 2
-------------------------------------

-------------------------------------
i = 13, miss = 6, hit = 7, page = 2
frame : 3 0 4 2
-------------------------------------

-------------------------------------
i = 14, miss = 6, hit = 8, page = 3
frame : 3 0 4 2
-------------------------------------

 */

// --------------------------------------- FCFS ------------------------------------------------
int incrementCount(int val){
    if(val == frameSize - 1){
        return 0;
    } else {
        return val + 1;
    }
}


void FCFS(){
    int count = 0, hit = 0, miss = 0;
    for (int i = 0; i < pageSize; i++) {
        if(frames[i] == -1){
            miss++;
            frames[count] = pages[i];
            count = incrementCount(count);
        }
        else{
            if(checkHit(pages[i]) > -1){
                hit++;
            } else {
                miss++;
                frames[count] = pages[i];
                count = incrementCount(count);
            }
        }
        print(i, hit, miss, pages[i]);
    }
}

void runAppFCFS(){
    initPages();
    FCFS();
}

// --------------------------------------- OP -----------------------------

/*
 *  {1,3,0,3,5,6,3} frame size = 3
-------------------------------------
i = 1, miss = 1, hit = 0, page = 1
frame : 1 -1 -1
-------------------------------------

-------------------------------------
i = 2, miss = 2, hit = 0, page = 3
frame : 1 3 -1
-------------------------------------

-------------------------------------
i = 3, miss = 3, hit = 0, page = 0
frame : 1 3 0
-------------------------------------

-------------------------------------
i = 4, miss = 3, hit = 1, page = 3
frame : 1 3 0
-------------------------------------

-------------------------------------
i = 5, miss = 4, hit = 1, page = 5
frame : 5 3 0
-------------------------------------

-------------------------------------
i = 6, miss = 5, hit = 1, page = 6
frame : 5 6 0
-------------------------------------

-------------------------------------
i = 7, miss = 6, hit = 1, page = 3
frame : 5 6 3
-------------------------------------
 */

// -------------------------------------- LRU ----------------------------------------

int *usage;

void initUsage(){
    int *temp = malloc(sizeof(int) * frameSize);

    for (int i = 0; i < frameSize; i++) {
        temp[i] = 0;
    }

    usage = temp;
}

int getLeast(){
    int min = 999999, index;
    for (int i = 0; i < frameSize; i++) {
        if(min > usage[i] && usage[i] != 0){
            min = usage[i];
            index = i;
        }
    }
    return index;
}

void printLRU(int i, int hit , int miss, int page) {
    i++;
    printf("-------------------------------------\n");
    printf("i = %d, miss = %d, hit = %d, page = %d\n", i, miss, hit,page);
    printf("frame : ");
    for (int i = 0; i < frameSize; i++) {
        printf("%d ", frames[i]);
    }
    printf("\n");
    printf("usage : ");
    for (int i = 0; i < frameSize; i++) {
        printf("%d ", usage[i]);
    }

    printf("\n-------------------------------------\n");

}

void leastRecentlyUsed(){
    int count = 0, hit = 0, miss = 0, u;
    for (int i = 0; i < pageSize; i++) {
        if(frames[i] == -1){
            miss++;
            frames[count] = pages[i];
            usage[i]++;
            count = incrementCount(count);
        }
        else{
            u = checkHit(pages[i]);
            if(u > -1){
                hit++;
                usage[u]++;
            } else {
                miss++;
                count = getLeast();
                usage[count]++;
                frames[count] = pages[i];
                usage[count] = 0;
            }
        }
        printLRU(i, hit, miss, pages[i]);
    }

}

void runAppLRU(){
    initPages();
    initUsage();
    leastRecentlyUsed();
}

// ------------------------------------ OP -----------------------------
/*
[7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3] frame size = 4
 -------------------------------------
i = 1, miss = 1, hit = 0, page = 7
frame : 7 -1 -1 -1
usage : 1 0 0 0
-------------------------------------
-------------------------------------
i = 2, miss = 2, hit = 0, page = 0
frame : 7 0 -1 -1
usage : 1 1 0 0
-------------------------------------
-------------------------------------
i = 3, miss = 3, hit = 0, page = 1
frame : 7 0 1 -1
usage : 1 1 1 0
-------------------------------------
-------------------------------------
i = 4, miss = 4, hit = 0, page = 2
frame : 7 0 1 2
usage : 1 1 1 1
-------------------------------------
-------------------------------------
i = 5, miss = 4, hit = 1, page = 0
frame : 7 0 1 2
usage : 1 2 1 1
-------------------------------------
-------------------------------------
i = 6, miss = 5, hit = 1, page = 3
frame : 3 0 1 2
usage : 0 2 1 1
-------------------------------------
-------------------------------------
i = 7, miss = 5, hit = 2, page = 0
frame : 3 0 1 2
usage : 0 3 1 1
-------------------------------------
-------------------------------------
i = 8, miss = 6, hit = 2, page = 4
frame : 3 0 4 2
usage : 0 3 0 1
-------------------------------------
-------------------------------------
i = 9, miss = 6, hit = 3, page = 2
frame : 3 0 4 2
usage : 0 3 0 2
-------------------------------------
-------------------------------------
i = 10, miss = 6, hit = 4, page = 3
frame : 3 0 4 2
usage : 1 3 0 2
-------------------------------------
-------------------------------------
i = 11, miss = 6, hit = 5, page = 0
frame : 3 0 4 2
usage : 1 4 0 2
-------------------------------------
-------------------------------------
i = 12, miss = 6, hit = 6, page = 3
frame : 3 0 4 2
usage : 2 4 0 2
-------------------------------------
-------------------------------------
i = 13, miss = 6, hit = 7, page = 2
frame : 3 0 4 2
usage : 2 4 0 3
-------------------------------------
-------------------------------------
i = 14, miss = 6, hit = 8, page = 3
frame : 3 0 4 2
usage : 3 4 0 3
-------------------------------------
 */



int main() {
    runAppLRU();
    return 0;
}
