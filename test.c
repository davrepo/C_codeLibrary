#include <stdio.h>
#include <string.h>

void FooD1(int *p, int size){ // int (*p)[2] is also valid
	for(int i = 0; i < size; i++){ printf("%d ", p[i]); }
	printf("\n");
}

void FooD2(int (*p)[3], int size){ // int p[][2] is also valid
	for(int i = 0; i < size; i++){ printf("%d %d\n", p[i][0], p[i][1]); }
}

void FooD3(int (*p)[2][2], int size){ // int p[][2][2] is also valid
	for(int i = 0; i < size; i++){
		printf("%d %d %d %d\n", p[i][0][0], p[i][0][1], p[i][1][0], p[i][1][1]);
	}
}

int main(){
	int A[2] = {2, 5};

	int B[2][3] = {{2, 5}, {7, 9}};
	int B_OK[5][3] = {{2, 5}, {7, 9}, {3, 4}, {6, 1}, {0, 8}};
	int B_NOT_OK[2][4] = {{2, 5, 7, 9}, {3, 4, 6, 1}};

    int C[3][2][2] = {{{2, 5}, {7, 9}}, {{3, 4}, {6, 1}}, {{0, 8}, {11, 13}}};

	printf("A size: %d\n", sizeof(A));
	FooD1(A, 2);

	printf("B size: %d\n", sizeof(B));
	FooD2(B, 2);
	printf("B_OK size: %d\n", sizeof(B_OK));
	FooD2(B_OK, 5);
	// FooD2(B_NOT_OK, 2); // expected 'int (*)[3]' but argument is of type 'int (*)[4]'

	printf("C size: %d\n", sizeof(C));
	FooD3(C, 3);

}