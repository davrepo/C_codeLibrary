#include <stdio.h>

// the scope of INPUT_MAX is the entire file
#define INPUT_MAX 16

int main()
{
	char input[INPUT_MAX];

	printf("Instructions: ");
	fgets(input,INPUT_MAX,stdin);
	puts("Thank you! Here are your instructions:");
	puts(input);

	return(0);
}

