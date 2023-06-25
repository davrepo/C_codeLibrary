#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Allocate passed pointer's memory 
read a string from stdin, to be stored at the passed pointer's address
Ensure any newline character \n is removed from the string
*/
void get_input(char **b) {
	// allocate memory for the string
	*b = (char *)malloc(10 * sizeof(char));

	// read a string from stdin
	printf("Enter name: ");
	fgets(*b, 10, stdin);

	// remove the newline character
	(*b)[strlen(*b) - 1] = '\0';
}

int main()
{
	// declare an arry of 5 pointers
	char *str[5]; // char **str

	// loop to send each pointer in the array to the get_input function for allocation and filling
	for (int i = 0; i < 5; i++) {
		get_input(&str[i]);
	}

	// main() then outputs the 5 strings
	for (int i = 0; i < 5; i++) {
		printf("%s\n", str[i]);
	}

	return(0);
}
