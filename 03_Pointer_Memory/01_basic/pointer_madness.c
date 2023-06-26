#include <stdio.h>
#include <stdlib.h>

int main() {
	int *p = (int *) malloc(8 * sizeof(int));
	for (int nb = 0; nb < 8; nb++) {
		p[nb] = nb + 1; // p[nb] is equivalent to *(p + nb)
	}

	printf("%p and %d \n", p, *p); // 0000000000715DA0 and 1

	// *p++
	// *p++ == *(p++) b/c unary operator reads from right to left, 
	// however p++ is post increment, so *p evaluated first, then p++
	// This effectively gets the value at the memory location that p pointed to before the increment, 
	// and p is incremented to point to the next memory location
	int a = *p++;
	printf("%d \n", a); // 1
	int *newptr = p;
	printf("%p \n", newptr); // 0000000000715DA4 (advance by 4 bytes)

	// *(p++)
	// The parentheses in *(p++) are redundant in this case, 
	// because the post-increment operator ++ has the same level of precedence 
	// as the dereference operator * and they are both right-to-left associative.
	// Still, this effectively gets the value at the memory location that p pointed to before the increment,
	// and p is incremented to point to the next memory location
	int b = *(p++);
	printf("%d \n", b); // 2
	newptr = p;
	printf("%p \n", newptr); // 0000000000715DA8 (advance by 4 bytes)

	// (*p)++ is same as *p = *p + 1
	// dereference p, assign that value to c (3),
	// then increment the value at the memory location that p pointed to 4!!! (Value CHANGED)
	// p pointer does not advance
	int c = (*p)++;
	printf("%d \n", c); // 3 !!!
	newptr = p;
	printf("%p \n", newptr); // 0000000000715DA8 (does NOT advance) !!!

	// *++p
	// advance p by 4 bytes, then dereference
	int d = *++p;
	printf("%d \n", d); // 4
	newptr = p;
	printf("%p \n", newptr); // 0000000000715DAC (advance by 4 bytes)

	// *(++p) is same as *++p
	// advance p by 4 bytes, then dereference
	int e = *(++p);
	printf("%d \n", e); // 5
	newptr = p;
	printf("%p \n", newptr); // 0000000000715DB0 (advance by 4 bytes)

	// ++*p
	// dereference p, 
	// then increment the value at the memory location that p pointed to from 5 to 6!!! (Value CHANGED)
	// assign that 6 to f
	// p pointer does not advance
	int f = ++*p;
	printf("%d \n", f);  // 6 !!!
	newptr = p;
	printf("%p \n", newptr); // 0000000000715DB0 (does NOT advance) !!!

	// ++(*p) is same as ++*p
	int g = ++(*p);
	printf("%d \n", g); // 7 !!!
	newptr = p;
	printf("%p \n", newptr); // 0000000000715DB0 (does NOT advance) !!!

	return(0);
}
