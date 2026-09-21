// Write a C program to rotate an array to the right by K positions without using another array. Array: 1 2 3 4 5 6 K = 2 Output: 5 6 1 2 3 4
#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void rotateRight(int arr[], int n, int k) {
    k = k % n; 
    if (k == 0) return;
    reverse(arr, 0, n - 1);
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    rotateRight(arr, n, k);
    printf("Output: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
