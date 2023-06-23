#include <stdio.h>

// scanf() is good for reading numbers, single characters, and strings without spaces (word)
// not good for reading strings with spaces in them (use fgets() instead) and can be overflown

int main()
{
    int age;
    printf("Enter your age: ");
    // scanf takes & pointer for types other than strings (char arrays)
    scanf("%d", &age);
    printf("You are %d years old.", age);
    return 0;
}