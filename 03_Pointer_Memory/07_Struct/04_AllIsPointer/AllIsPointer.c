#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct person {
		char *name;
		int *age;
	} *first;

	first = (struct person *)malloc( sizeof(struct person) * 1);
	if( first==NULL ) {
		fprintf(stderr,"Unable to allocate storage\n");
		exit(1);
	}
	
	// allocate structure members
	first->name = (char *)malloc( sizeof(char) * 32);
	first->age = (int *)malloc( sizeof(int) * 1);
	if( first->name==NULL || first->age==NULL ) {
		fprintf(stderr,"Unable to allocate storage\n");
		exit(1);
	}

	// assign structure members
	strcpy(first->name,"George");
	printf("How old was %s? ", first->name);
    // scanf() takes a pointer as its 2nd argument and attempts to convert to an int
	// first->age is a pointer to an int, so no need &
	scanf("%d", first->age);

	printf("%s was %d years old\n", first->name, *first->age);

	return(0);
}
