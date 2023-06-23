#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct human {
		char *name;
		int age;
	} *towrite;
	const char filename[] = "saved.dat";
	char *r;
	FILE *fp;

	/* allocate structure */
	towrite = (struct human *)malloc( sizeof(struct human) * 1);
	if( towrite==NULL ) {
		fprintf(stderr,"Unable to allocate structure memory\n");
		exit(1);
	}
	/* now that structure is allocated, allocate storage for the name pointer */
	towrite->name = (char *)malloc( sizeof(char) * 32);
	if( towrite->name==NULL ) {
		fprintf(stderr,"Unable to allocate string memory\n");
		exit(1);
	}

	/* fill the towrite structure; prompt the user */
	printf("Enter your name: ");
	r = fgets(towrite->name, 32, stdin);
	if( r==NULL ) {
		fprintf(stderr,"Input error\n");
		exit(1);
	}
	printf("How old are you: ");
	/* towrite->age is an integer, not a pointer, so & is required */
	scanf("%d", &towrite->age);

	/* write the structure to a file */
	/* open the file */
	fp = fopen(filename,"w");
	if( fp==NULL ) {
		fprintf(stderr,"Unable to create %s\n",filename);
		exit(1);
	}
	/* write the structure */
    // fwrite(towrite, sizeof(struct human), 1, fp); <== is WRONG
    // if you want to save struct to file, member must not be pointer
    // otherwise, memory address is saved, not the data. 
    // In order to save both the name and age to the file, you need to write them separately.

    // write the string and the null-terminating character
	fwrite(towrite->name, sizeof(char), strlen(towrite->name)+1, fp); 
	fwrite(&towrite->age, sizeof(int), 1, fp); // write the age

	fclose(fp);
	printf("Data written to %s\n",filename);
	
	return(0);
}
