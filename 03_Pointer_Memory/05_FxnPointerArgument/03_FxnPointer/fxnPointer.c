#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int performCalc(int a, int b, int (*fxn)(int, int)) { 
	// fxn is a pointer to a function that takes 2 ints and returns an int
	return fxn(a, b);
}

int main() { 
	int a = 10, b = 5;
	printf("Add: %d\n", performCalc(a, b, add));
	printf("Sub: %d\n", performCalc(a, b, sub));
	printf("Mul: %d\n", performCalc(a, b, mul));
	printf("Div: %d\n", performCalc(a, b, div));
}

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

int div(int a, int b) {
	return a / b;
}

