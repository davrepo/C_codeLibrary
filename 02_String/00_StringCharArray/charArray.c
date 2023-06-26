#include <stdio.h>
#include <string.h>

int main() {
	char A[10];
	A[0] = 'A';
	A[1] = 'B';
	A[2] = 'C';
	printf("%s\n", A); // ABC
	//sizeof
	printf("Size of A = %d\n", sizeof(A)); // 10
	//strlen reads until it finds a null character
	printf("Length of A = %d\n", strlen(A)); // 3

	char B[10] = {'A', 'B', 'C', '\0'}; // null char must be explicity
	char C[10] = "ABC"; // string literal, null char is implicity
	char D[] = "ABC";
	char *E = "ABC"; // char *E is a pointer to a string literal
	E++; 
	
	// will not compile
	// array variable is a constant pointer to the 1st element of the array, 
	// is not modifiable, i.e. cannot use the assignment operator (=) to change the address it points to, 
	// i.e. cannot assign a new value directly to an array in the way you're trying to do with E = "John".
	// must use strcpy() to copy a string to an array instead
	char F[10];
	F = "ABC"; // error: array type 'char [10]' is not assignable

	strcpy(E, "ABC"); // works fine

	return(0);
}
