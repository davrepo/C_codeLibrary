#include <stdio.h>

void modifyArray(char *C){ 
	C++; // allowed
}

int main(){
    char *C = "Hello";
	modifyArray(C);
	printf("%s\n", C); // Hello
}