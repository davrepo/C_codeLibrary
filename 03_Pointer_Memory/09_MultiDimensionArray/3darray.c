#include <stdio.h>
#include <string.h>

int main(){
	//  When you refer to an array without an index, it decays into a pointer to the 1st element of the array.
    int C[3][2][2] = {{{2, 5}, {7, 9}}, {{3, 4}, {6, 1}}, {{0, 8}, {11, 13}}};

	int (*a)[2][2] = C; // points to 1st element, 'a' is a pointer type 2x2 (2D) array of int 
	int (*b)[2][2] = &C[0]; // == a
	int (*c)[3][2][2] = &C; // points to the ENTIRE 3D array of int, b/c &C is the address for the entire array

	printf("(**a)[1][1] = %d\n", (*a)[1][1]); // 9
	printf("(*c)[1][1][1] = %d\n", (*c)[1][1][1]); // 1

	int e[2][2];
	memcpy(e, *C, sizeof(e));

	int f[2][2];
	memcpy(f, C[1], sizeof(f));

	int *g = &C[0][0][0];

	int (*h)[2][2] = C + 1; // pointer to 2nd 2x2 array

	printf("*(C[0][1] + 1) or C[0]][1][1] = %d\n", *(C[0][1] + 1)); // 9

	// C+1, incrementing pointer by 1 which moves it to the second 2D array. 
	// *(C+1) gives the actual 2D array {{3, 4}, {6, 1}}.
	// decays to a pointer to an 1x2 1D array.
	// +2 moves pointer by 2* (2x4) bytes
	// *(C+1)+2 gives the pointer to 1D array {0, 8}.
	int (*i)[2] = *(C+1)+2; // pointer to 0
	int (*j)[2] = C[1]+2;

	// same as *(C+1)+3
	int (*k)[2] = *(C+1)+2+1; // pointer to 1
	int (*l)[2] = C[1]+2+1;

	printf("%d %d %d %d\n", C, *C, C[0], &C[0][0]);
	// 6422000 6422000 6422000 6422000
	printf("%d\n", *(C[0][0] + 1)); // 5
}