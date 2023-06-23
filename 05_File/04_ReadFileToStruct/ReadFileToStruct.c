#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct human {
	char *name;
	int age;
};

int main() {
	struct human *readback;
	const char filename[] = "saved.dat";
	FILE *fp;

	/* allocate structure */
	readback = (struct human *)malloc(sizeof(struct human) * 1);
	if (readback == NULL) {
		fprintf(stderr, "Unable to allocate structure memory\n");
		exit(1);
	}

	/* Now that structure is allocated, allocate storage for the name pointer */
	readback->name = (char *)malloc(sizeof(char) * 32);
	if (readback->name == NULL) {
		fprintf(stderr, "Unable to allocate string memory\n");
		exit(1);
	}

	/* Open the file */
	fp = fopen(filename, "r");
	if (fp == NULL) {
		fprintf(stderr, "Unable to open %s\n", filename);
		exit(1);
	}

	/* Read the name and age separately */
	fread(readback->name, sizeof(char), 32, fp); // Read the string
	fread(&readback->age, sizeof(int), 1, fp); // Read the age

	fclose(fp);

	printf("Data read from %s\n", filename);
	printf("Name: %s\n", readback->name);
	printf("Age: %d\n", readback->age);

	return 0;
}
