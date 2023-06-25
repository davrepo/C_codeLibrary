#include <stdio.h>

int main() {
	// ---------------------- Take Home Pointer ----------------------
    // for array, unless you're using the & or sizeof operator, 
    // the array name is pointer to the first element
    
    // ---------------------- ARRAY ----------------------
	int arr[6]; // allocate in stack 6 * 4 bytes in memory
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;

	printf("%p == %p\n", arr, &arr[0]); // arr is pointer to 1st element of array
	// 000000000061FDF0 == 000000000061FDF0

	for (int i=0; i<6; i++) {
		// *arr++ is not allowed even though is pointer, b/c arr is *like* a constant pointer
        // but *(arr + i) is allowed
		printf("%d, ", arr[i]); // 1, 2, 3, 0, 8, 0, 
	}

	// size of arr is not size of pointer, but size of entire array
	printf("size of arr: %zu, %zu\n", sizeof(arr), sizeof(int) * 6); 
    // size of arr: 24 (size of array, not size of pointer)

	printf("%p\n", &arr); // 000000000061FE00
	printf("%p\n", arr); // 000000000061FE00

	// pointer arithmetic
	// &arr has data type int (*)[6] == int *arr[6]: pointer to array of 6 ints
	// it is not int *[6]: array of 6 pointers to int
	printf("%p\n", &arr + 1); // 000000000061FE18 // 24 bytes added (advance 6 positions)
	// arr has data type int * (4 bytes)
	printf("%p\n", arr + 1); // 000000000061FE04 // 4 bytes added (advance 1 position)

	puts("\n");

	// ---------------------- FAKE ARRAY ----------------------
	int *ptr = alloca(sizeof(int) * 6); // allocate in stack 6 * 4 bytes in memory
	*(ptr) = 1;
	*(ptr + 1) = 2;
	*(ptr + 2) = 3;

	for (int i=0; i<6; i++) {
		/*
		ptr++ works but you are changing the pointer, ptr = ptr + 1
		if ptr is a const ptr, then ptr++ is not allowed
		i.e. int *const ptr = alloca(sizeof(int) * 6);
		*/
		
		printf("%d, ", *(ptr + i)); // 1, 2, 3, 0, 8, 0, 
	}

	// normal pointer is 8 bytes (64 bit architecture)
	printf("size of ptr: %zu, %zu\n", sizeof(ptr), sizeof(int *)); // size of ptr: 8

	printf("%p\n", &ptr); // 000000000061FDF8
	printf("%p\n", ptr); // 000000000061FDC0

	printf("%p\n", &ptr + 1); // 000000000061FE00 // 8 bytes added (advance 1 position of 8 byte pointer architecture)
	printf("%p\n", ptr + 1); // 000000000061FDC4 // 4 bytes added (advance 1 position of int size)

    // ---------------------- EXTRA ----------------------
    int v[10];
    v[1] = 42;
    printf("%d\n", v[1]); // 42 // v[1] is translated to *(v + 1)
    printf("%d\n", *(v + 1)); // 42
    printf("%d\n", 1[v]); // 42 // same as v[1], because 1[v] is translated to *(1 + v)
    printf("%d\n", *(1 + v)); // 42

    // ---------------------- String literal ----------------------
    printf("%s\n", "Hello"); // Hello
    printf("%c\n", "Hello"[0]); // H
    printf("%c\n", *"Hello"); // H
    printf("%c\n", 0["Hello"]); // H
    printf("%c\n", 2["Hello"]); // l
    printf("%c\n", *("Hello" + 1)); // e

    return 0;
}

