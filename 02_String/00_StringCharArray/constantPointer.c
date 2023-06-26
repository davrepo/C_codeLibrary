#include <stdio.h>

void modifyArray(const char *C) // same as char const C[]
{ 
    printf("%s\n", C); // Hello

    // you can change what C points to
    // but not the content it points to
    C++; // allowed
    printf("%s\n", C); // ello

    *C = 'A'; // not allowed
    C[0] = 'A'; // not allowed
}

int main(){
    char C[] = "Hello";
    modifyArray(C);
    printf("%s\n", C); // Hello
}