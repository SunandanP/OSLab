#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;  // Item not found
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <sorted_array>\n", argv[0]);
        return 1;
    }

    int sortedArray[6];
    sscanf(argv[1], "%d %d %d %d %d %d", &sortedArray[0], &sortedArray[1], &sortedArray[2], &sortedArray[3], &sortedArray[4], &sortedArray[5]);

    int key = 5; // Item to search for
    int index = binarySearch(sortedArray, 6, key);
    if (index != -1) {
        printf("Item %d found at index %d.\n", key, index);
    } else {
        printf("Item %d not found in the array.\n", key);
    }

    return 0;
}

