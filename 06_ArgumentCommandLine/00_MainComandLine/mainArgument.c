#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) { // same: char **argv, char argv[][]
    // Check if the correct number of arguments is provided
    if (argc != 3) {
        printf("Invalid input.\n");
    } else {
        // Parse the command line arguments
        int num_plants = atoi(argv[1]);
        float price_per_plant = atof(argv[2]);

        // Calculate the total price
        float total_price = num_plants * price_per_plant;

        // Generate the invoice
        printf("%d plants for %.2f dollars each cost %.2f dollars.\n", num_plants, price_per_plant, total_price);
    }

    return 0;
}

// .\mainArgument.exe 3 5
// 3 plants for 5.00 dollars each cost 15.00 dollars.