#include <stdio.h>

int main() {
    int grade;
    
    // Read the grade from the user
    scanf("%d", &grade);
    
    // Open the file for reading
    FILE *file = fopen("myGrades.txt", "r");
    
    // Find the last number in the file
    // reading integers (grades) from the opened file one by one until it can't read any more.
    // The fscanf function is used to read formatted data from the file. The format specified ("%d") tells fscanf to look for an integer.
    // fscanf reads one integer at a time and stores it in the variable lastGrade. It keeps doing this in a loop as long as it can successfully read an integer.
    // When fscanf encounters the end of the file, or some data that it can't interpret as an integer, it will return a value that is not equal to 1. At this point, the loop stops.
    int lastGrade;
    while (fscanf(file, "%d", &lastGrade) == 1) {
        // Move to the next number
    }
    
    // Close the file
    fclose(file);
    
    // Compare the last grade with the grade from the user
    if (lastGrade == grade) {
        printf("Grade already recorded.\n");
    } else {
        // Reopen the file for appending
        file = fopen("myGrades.txt", "a");
        
        // Append the new grade to the file
        fprintf(file, " %d", grade);
        
        // Close the file
        fclose(file);
    }
    
    // Reopen the file for reading
    file = fopen("myGrades.txt", "r");
    
    // Print the file contents
    while (fscanf(file, "%d", &lastGrade) == 1) {
        printf("%d ", lastGrade);
    }
    printf("\n");
    
    // Close the file
    fclose(file);
    
    return 0;
}
