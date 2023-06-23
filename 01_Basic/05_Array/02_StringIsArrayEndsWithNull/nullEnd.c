#include <stdio.h>

int main()
{
	char hello[] = "Greetings, human!\n";
	int n;

	n = 0;
    // final character in a string is always '\0'
	while( hello[n] != '\0') // '\0' is the null character
	{
		putchar(hello[n]);
		n++;
	}

	return(0);
}
