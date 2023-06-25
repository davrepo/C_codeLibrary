#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *weekdays[] = {"Tue", "Mon", "Wed"}; // an array of pointers

	char *temp;
	int x, y;

	/* output original array */
	puts("Unsorted:");
	for( x=0; x<3; x++ ) printf(" %s\n", weekdays[x]);

	/* sort the array, bubble sort */
	for( x=0; x<2; x++ ) {
		for( y=x+1; y<3; y++ ) {
			// weekdays[x] == *(weekdays + x),
            // which returns a pointer that points to the first char of the string
			if( strcmp(weekdays[x], weekdays[y]) > 0 ) 
			{
				temp = weekdays[x];
				weekdays[x] = weekdays[y];
				weekdays[y] = temp;
			}
		}
	}

	/* output the sorted result */
	puts("Sorted:");
	for( x=0; x<3; x++ ) printf(" %s\n",weekdays[x]);

	return(0);
}
