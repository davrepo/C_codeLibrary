#include <stdio.h>
#include <ctype.h>

char *encrypt(char *input);

int main()
{
	char *text = "Some random text";
	printf("Encrypted text:\n%s\n",encrypt(text));
	return(0);
}

char *encrypt(char *input)
{
	char output[64]; // local variable
	
	int x = 0;
	while(*input)
	{
		if(isalpha(*input)) // if the character is a letter
			output[x] = *input + 1; // add 1 to the character
		else
			output[x] = *input; // otherwise, just copy the character
		x++;
		input++;
	}

	return(output);
}

