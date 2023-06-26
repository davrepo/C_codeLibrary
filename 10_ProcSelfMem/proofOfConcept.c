#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main() {
    char *a = "Hej abcdef"; // Ligger nu i data sektion

    printf("Her ligger a: %p\n", a);
    printf("Dette er beskeden: %s\n", a);

    int fil_handler = open("/proc/self/mem", O_WRONLY); // Åben den i write only mode
    off_t our_offset = (off_t)a; // offset til addressen a (bare addressen)

    lseek(fil_handler, our_offset, SEEK_SET); // flyt positionen hen til det offset

    char *ny_besked = "LOL sejt!\x00\x00";
    write(fil_handler, ny_besked, strlen(a)); // skriver nu til det offset

    printf("Her ligger a: %p\n", a);
    printf("Dette er beskeden: %s\n", a);
}

/*
 * OUTPUT:
 * ; ./a.out
 * Her ligger a: 0x55a1d07f5004
 * Dette er beskeden: Hej abcdef
 * Her ligger a: 0x55a1d07f5004
 * Dette er beskeden: LOL sejt!
*/