#include <stdio.h>

// scanf() is good for reading numbers, single characters, and strings without spaces (word)
// not good for reading strings with spaces in them (use fgets() instead) and can be overflown (b/c has no limit on how many characters it can read)
// so use fgets() instead of scanf() for reading strings with spaces in them

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

    /* Example 3*/

    char *str = malloc(100); // Allocate memory for the string
    if (str == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return 1;
    }
    
    scanf("%99[^\n]", str); // Read a line of text, but not more than 99 characters (leave space for null terminator)
    getchar(); // get rid of the newline character left behind by scanf
    printf("\n%s\n", str);

    free(str); // Free the allocated memory

    return 0;
}