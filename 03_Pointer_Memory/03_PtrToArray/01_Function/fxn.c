#include <stdio.h>

#define SIZE 50

void foo(int arr[]) {
    printf("%p\n", arr); // 000000000061FC90
}

void bar(int *arr) { // same as int arr[]
    printf("%p\n", arr); // 000000000061FC90
}

void printElement(int *v, int size) { // size anchor
    for (int i=0; i<size; i++) {
        printf("%d, ", v[i]);
    }
}

int main() {
    int arr[10];
    foo(arr);
    bar(arr);

    // -------------- Size Anchor --------------
    int v[SIZE];
    for (int i=0; i<SIZE; i++) {
        v[i] = rand() % 100;
    }
    printElement(v, SIZE);

    return 0;
}