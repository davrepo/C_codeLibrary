#include <stdio.h>

int main()
{
	const char filename[] = "integers.dat";
	FILE *fp;
	int x,a;

	/* open and create the file */
	fp = fopen(filename,"w");
	if( fp == NULL )
	{
		printf("Unable to create %s\n",filename);
		return(1);
	}

	/* write the integers */
	a = 10;
	for(x=0;x<10;x++)
	{
		// fwrite() is a binary function, so it doesn't care about the type of data
		// it's writing. It just writes the data as it is. So, if you want to write
		// an integer, you have to tell it how many bytes to write. In this case,
		// we're writing an integer, so we tell it to write the size of an integer.
		// The size of an integer is given by the sizeof() function.
		// fwrite() returns the number of items written, so if it returns 0, then
		// it didn't write anything.

		// fwrite() writes the BINARY representation of the data, not the text representation.
		fwrite(&a, sizeof(int), 1, fp); // arguements: address of variable, size of variable, number of variables, file pointer
		a += 5;
	}

	/* and remember to close */
	fclose(fp);

	return(0);
}

