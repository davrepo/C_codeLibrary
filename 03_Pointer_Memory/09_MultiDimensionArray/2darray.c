#include <stdio.h>
#include <string.h>

int main() {
	int B[2][3] = {{2, 3, 6}, {4, 5, 8}};
	// int *a = B; // Wrong, B is pointer to 1st row, type int (*)[3], i.e. pointer to an array of 3 integers
	// however, size(B) represents the entire 2D array, and is considered type int [2][3]
	
	/* 400 (Pointer at address 400) */
	int (*a)[3] = B; // Pointer to an array of 3 ints
	int (*b)[3] = &B[0]; // explicitly take the address of 1st elem of B, i.e. the first row
	int (*c)[2][3] = &B; // &B gives pointer to the entire 2D array

	// int d[3] = *B; // *B gives the first row, which is an array of 3 ints
	// but cannot initialize an array with another array, so use memcpy
	int d[3];
	memcpy(d, *B, sizeof(d));
	int *e = *B; // however, can decay to int *, b/c it's the address of the first element of the first row

	// int f[3] = B[0]; // B[0] gives the first row, which is an array of 3 ints
	int f[3];
	memcpy(f, B[0], sizeof(f));
	int *g = B[0]; // however, can decay to int*, b/c it's the address of the first element of the first row

	int *h = &B[0][0]; // address of the first integer of the first row, i.e. address of that is int *
	
	
	/* 412 (Pointer at address 412) */ 
	int (*i)[3] = *(B + 1); // gives the second row, which is an array of 3 ints (by dereferencing B + 1)
	int *j = *(B + 1); // however, can decay to int *, b/c it's the address of the first element of the second row
	int k[3];
	memcpy(k, B[1], sizeof(k)); // B[1] gives the second row, which is an array of 3 ints - this is direct copy
	int *l = B[1]; // however, can decay to int*, b/c it's the address of the first element of the second row

	int *m = &B[1][0]; // address of the first integer of the second row, i.e. address of that is int *
	
	/* 420 (Pointer at address 420) */
	// B+1 gives pointer to 2nd row => *(B+1) deref get actual 2nd row, which is array of 3 ints
	// => which decays to array pointer, adding 2 gives pointer to 3rd element in 2nd row. 
	int *n = *(B+1)+2; 
	// B[1] like *(B+1) is direct ref to 2nd row, which is array of 3 ints. Decays to array pointer
	// adding 2 gives pointer to 3rd element in 2nd row
	int *o = B[1]+2; 
	// &B[1][2] is address of 3rd element in 2nd row, which is int *
	int *p = &B[1][2];

	// *(*B + 1) == *(*(B + 0) + 1) == *(B[0] + 1) == B[0][1] == 3
	// B[i][j] = *(B[i] + j) = *(*(B + i) + j)
	// *B same as B[0], is the 1st row, which is array of 3 ints, decays to array pointer
	// +1 gives pointer to 2nd element in 1st row, which is int *
	// * deref gives the actual int value, 3
	printf("*(*B + 1) = %d\n", *(*B + 1)); // 3

	/* General */
	// B[i][j] = *(B[i] + j) = *(*(B + i) + j)

	// *B[0] + 1
	// B[0] is the 1st row, which is array of 3 ints, decays to array pointer
	// *B[0] is the 1st element in 1st row, which is 2
	// 2 + 1 == 3, but you are doing arithmetic on an int, not advancing pointer

	return(0);
}
