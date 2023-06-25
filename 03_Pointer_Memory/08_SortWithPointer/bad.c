#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char weekdays[3][5] = {"Tue", "Mon", "Wed"};

	char temp[5];
	int x,y;

	/* output original array */
	puts("Unsorted:");
	for( x=0; x<3; x++ ) printf(" %s\n",weekdays[x]);

	/* sort the array, bubble sort */
	for( x=0; x<2; x++ ) {
		for( y=x+1; y<3; y++ ) {
			/* Sort alphabetically, A to Z */
			if( strcmp(weekdays[x], weekdays[y]) > 0 )
			{
				strcpy(temp, weekdays[x]);
				strcpy(weekdays[x] ,weekdays[y]);
				strcpy(weekdays[y], temp);
			}
		}
	}

	/* output the sorted result */
	puts("Sorted:");
	for( x=0; x<3; x++ ) printf(" %s\n",weekdays[x]);

	return(0);
}
