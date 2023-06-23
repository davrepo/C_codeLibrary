#include <stdio.h>

// scanf() is good for reading numbers, single characters, and strings without spaces (word)
// not good for reading strings with spaces in them (use fgets() instead) and can be overflown

int main()
{
    /* Example 1*/
    int age;
    printf("Enter your age: ");
    // scanf takes a pointer as its second argument
    scanf("%d", &age);
    printf("You are %d years old.", age);

    /* Example 2*/
    int age;
	int *ptr;

	// must always initialize a pointer
	ptr = &age; // initialize pointer to point to age

	printf("Your age: ");
	scanf("%d", ptr);
	printf("You are %d years old\n", *ptr);

    return 0;
}