#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct person {
		char name[32];
		int age;
	} *first;

	// allocate the structure's memory
	first = (struct person *)malloc( sizeof(struct person) * 1);
	if( first==NULL ) {
		fprintf(stderr,"Unable to allocate storage\n");
		exit(1);
	}

	// first->name = "George" || (*first).name = "George" will not work
    // see explanation
	strcpy(first->name, "George");
	printf("How old was %s? ", first->name);
	
	// scanf() reads a word and assigns it to the first->age member
	// scanf() takes a pointer as its 2nd argument and attempts to convert to an int
	// if fails, it returns 0. Failure not checked here.
	scanf("%d", &first->age);

	printf("%s was %d years old\n", first->name, first->age);

	return(0);
}
