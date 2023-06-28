#include <stdio.h>

int main() {
	int C[3][2][2] = {{{2, 5}, {7, 9}}, {{3, 4}, {6, 1}}, {{0, 8}, {11, 13}}};
	int (*n)[2] = *(C+1)+2;  // n is a pointer to an array of two integers
	printf("*(C+1)+2 = %d\n", **n);

	return(0);
}
