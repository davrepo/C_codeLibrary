#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int a[] = { 100, 101, 102, 103 };
	int b[4];

	memcpy(b, a, sizeof(int)*4); // copy a to b

	for(int x=0; x<sizeof(a)/sizeof(a[0]); x++) printf("%d = %d\n", a[x], b[x]);
    // 100 = 100
    // 101 = 101
    // 102 = 102
    // 103 = 103

	return(0);
}
