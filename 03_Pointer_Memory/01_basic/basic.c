#include <stdio.h>

int main()
{
    int pokey; // declare an integer
	int *p; // declare a pointer to an integer

	pokey = 987;
	p = &pokey; // assign address of pokey to pointer p

    // same address
	printf("The address of `pokey` is %p\n",&pokey); // 000000000061FE14
	printf("The address of `p` is %p\n",p); // 000000000061FE14

	printf("The value of `pokey` is %d\n",pokey); // 987
	printf("The value of `*p` is %d\n",*p); // 987  // dereference pointer p to get value of pokey

	return(0);
}
