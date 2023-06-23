#include <stdio.h>
#include <string.h>

int main()
{
	char first[] = "I would like to go ";
	char second[] = "from here to there\n";
    // printf("concat with + will not work in C\n", first + second);
	char buffer[50];

	strcpy(buffer,first); // copy first into buffer
	strcat(buffer,second); // concatenate second onto buffer
	puts(buffer);

	return(0);
}

