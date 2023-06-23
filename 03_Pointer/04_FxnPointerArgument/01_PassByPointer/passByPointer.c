#include <stdio.h>
#include <string.h>

char *longer(char *s1, char *s2);

int main()
{
	char string1[] = "Constantinople";
	char string2[] = "Byzantium";
	char *result;

    // string1 is decayed to a pointer to the first element of the array and passed to longer()
    // same as longer(&string1[0], &string2[0])
    // i.e. it is same as a char pointer to the first element, i.e. 'C'
	result = longer(string1,string2);
    // %s expects a char pointer as argument, so result is printed as a string
    // %s reads the string from the address pointed to by result until it encounters a null character
	printf("String '%s' is longer.\n",result);

	return(0);
}

char *longer(char *s1, char *s2)
{
	int len1,len2;

	len1 = strlen(s1);
	len2 = strlen(s2);

	if( len1 > len2 )
		return(s1);
	else
		return(s2);
}

