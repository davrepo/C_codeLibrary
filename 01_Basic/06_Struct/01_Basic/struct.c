#include <stdio.h>
#include <string.h>

int main()
{
	// define a structure
	struct date {
		int year;
		int month;
		int day;
	};
	struct person {
		char name[32];
        // nested structure
        // date struct be defined before person struct as above for it to be used here
		struct date birthday; 
	};
    // declare a variable of type struct person
	struct person friend;

    // friend.name = "George Washington" is not allowed, so we use strcpy
	strcpy(friend.name,"George Washington");
	friend.birthday.year = 1732;
	friend.birthday.month = 2;
	friend.birthday.day = 22;

	printf("My friend %s was born on %d/%d/%d\n",
			friend.name,
			friend.birthday.month,
			friend.birthday.day,
			friend.birthday.year);

	return(0);
}

