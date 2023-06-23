#include <stdio.h>
#include <ctype.h>

int main()
{
	int c;

    // Do-while loop is executed at least once
	do
	{
		c = getchar();
		c = toupper(c);
		putchar(c);
	}
	while( c != '\n');

	return(0);
}