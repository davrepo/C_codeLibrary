#include <stdio.h>

int main()
{
    // 4 rows, each row is a 5 character string, where the last character is '\0'
    // 1st row, "Ant" is stored as 'A', 'n', 't', '\0', '\0'
    // 4th row, "Duck" is stored as 'D', 'u', 'c', 'k', '\0'
	char names[4][5] = {
		"Ant",
		"Bee",
		"Cat",
		"Duck"
	};
	int x;

	for(x=0;x<4;x++)
		printf("%s\n",names[x]);

	return(0);
}

// Ant
// Bee
// Cat
// Duck