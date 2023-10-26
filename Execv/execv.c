#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int data[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(data) / sizeof(data[0]);
    
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
         if(data[j] < data[j+1]){
           int temp = data[j];
           data[j] = data[j+1];
           data[j+1] = temp;
         } 
      }
    }

    // Convert the sorted array to a string
    char sortedArrayStr[256];
    sprintf(sortedArrayStr, "%d %d %d %d %d %d", data[0], data[1], data[2], data[3], data[4], data[5]);

    // Create a child process
    pid_t child_pid = fork();

    if (child_pid == 0) {
        // Child process
        char* argv[] = {"./child", sortedArrayStr, NULL};
        execve("./find", argv, NULL);
        perror("execve");  // This line will be executed only if execve fails
        exit(1);
    } else if (child_pid > 0) {
        // Parent process
        wait(NULL);  // Wait for the child to finish
    } else {
        perror("fork");  // Fork failed
        exit(1);
    }

    return 0;
}
