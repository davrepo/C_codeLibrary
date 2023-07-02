#include <stdio.h>

int main() {
    // Open the input file
    FILE *file = fopen("gradeComparison.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    // Read your class's average grade
    float yourGrade;
    fscanf(file, "%f", &yourGrade);

    // Read and compare the average grades of other classes
    float otherGrade;
    int classNumber = 2;
    while (fscanf(file, "%f", &otherGrade) != EOF) { // Read until End Of File
        if (otherGrade > yourGrade) {
            printf("No %d\n", classNumber);
            return 0;
        }
        classNumber++;
    }

    fclose(file);

    // If no other class had a higher grade, your class did better
    printf("Yes\n");

    return 0;
}
