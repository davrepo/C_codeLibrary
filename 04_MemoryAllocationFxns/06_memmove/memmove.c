#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int a[] = { 100, 101, 102, 103, 104 };

	memmove(&a[1], a, sizeof(int)*4);

	for(int x=0; x<5; x++) printf("%d, ", a[x]);
    // 100, 100, 101, 102, 103, 

	return(0);
}
