#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct person {
		char name[32];
		int age;
	} president = {"George", 59};
	printf("%s is %d years old\n", president.name, president.age);
    // George is 59 years old
	
	struct person *first; // first is a pointer of type Person
	first = &president;

	/* output pointer reference */
    // first->name is the same as (*first).name
	printf("%s is %d years old\n", first->name, first->age); 
    // George is 59 years old

	return(0);
}
