#include <stdio.h>
#include <ctype.h>

void shouting(char *input);

int main()
{
	char string[64];

	printf("Type some text: ");
	fgets(string,64,stdin);
	printf("You typed:\n%s\n",string);
	shouting(string);
	printf("Convert to all caps:\n%s\n",string);

	return(0);
}

void shouting(char *input)
{
	while(*input) // while(*input != '\0')
	{
		*input = toupper(*input);
		input++;
	}
}

