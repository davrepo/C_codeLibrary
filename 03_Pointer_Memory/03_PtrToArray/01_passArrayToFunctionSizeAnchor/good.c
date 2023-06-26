#include <stdio.h>
#include <stdlib.h>

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
    int v[10];
    for (int i=0; i<sizeof(v)/sizeof(v[0]); i++) {
        v[i] = rand() % 100;
    }
    // sizeof(v)/sizeof(v[0]) is the size anchor
    printElement(v, sizeof(v)/sizeof(v[0]));
    // 41, 67, 34, 0, 69, 24, 78, 58, 62, 64,

    return 0;
}