#include <stdio.h>

int main()
{
	char *months[12] = {"Abe", "Bert", "Charl", "Davids"};
	int x;

	for(x=0; x<4; x++) printf("%s ", months[x]); // %s reads until '\0'
	// Abe Bert Charl Davids
	for(x=0; x<4; x++) printf("%p ", months[x]); // %p prints the address
	// 0000000000404000 0000000000404004 0000000000404009 000000000040400F
	// note above: +4, +5, +6 

	char *ptr;

	for(x=0; x<4; x++) {
		// month + x is the pointer of the xth string
		// *(month + x) dereferences the pointer and returns the address of the 1st char
		// the address of the 1st char is assigned to ptr
		ptr = *(months+x); // purist notation, same as ptr = months[x];
		while(*ptr) // while(*ptr != '\0')
		{
			putchar(*ptr);
			ptr++; // go to next char
		}
		putchar(' ');
	}
	// Abe Bert Charl Davids 

	return(0);
}

