#include <stdio.h>

int main()
{
    // string is a sequence of characters with a null character at the end
    // so length of string is one more than the number of characters in it
    char password[] = "password"; // [] means that the compiler will determine the size of the array
    printf("The passord is %s\n", password);
    printf("The length of the password is %d\n", sizeof(password)); // 9

    char name[15]; // has room for 14 characters and a null character
    printf("Enter your name: ");
    fgets(name, 15, stdin); // fgets() reads a string from the keyboard
    printf("Your name is %s\n", name);
    return 0;
}