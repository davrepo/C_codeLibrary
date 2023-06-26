#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = 1025;
	// 1025 = 00000000 00000000 00000100 00000001
	// 1st byte = 00000001 = 2^0 = 1
	// 2nd byte = 00000100 = 2^2 = 4
	int *p = &a;

	char *p_char;
	void *p_void;

	p_char = (char *) p;
	printf("1st byte of int a = %d \n", *p_char); // 1
	
	p_void = ((char *) p) + 1; // pointer arithmetic
	printf("2nd byte of int a = %d \n", *(char*)p_void); // 4 

	return(0);
}
