#include <stdio.h>

// problem with fgets() is that it reads the newline character (\n) as well
// so you have to remove the newline character from the string

int main()
{
	char input[64];		/* 63 characters plus null */

	printf("Instructions: ");
	fgets(input,64,stdin); // 64 is the maximum number of characters to read (including the null character)
	puts("Here are your instructions:");
	puts(input);

	return(0);
}

