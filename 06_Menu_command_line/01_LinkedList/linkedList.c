#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16
enum { FALSE, TRUE }; // FALSE = 0, TRUE = 1 by default
typedef struct family {
	char name[SIZE];
	char relationship[SIZE];
	int age;
	struct family *next;
};
char filename[] = "family.dat";

/* read standard input, discard newline */
char *input(void) // C uses f(void) to indicate fxn takes no param
{
	static char buffer[SIZE];
	char *r; // pointer to the first char read in by fgets()

	/* initialize the buffer */
	buffer[0]='\0';

	/* gather input */
	// fgets() stops when it reads in a newline or EOF
	// returns a pointer to the first char in the buffer or NULL if fails
	// buffer = fgets(buffer, SIZE, stdin) will not compiled
	// b/c buffer is an array and cannot be assigned to in C
	r = fgets(buffer, SIZE, stdin); 
	if( r==NULL ) {
		fprintf(stderr,"Input error\n");
		exit(1);
	}
	
	/* remove the newline /n */
	for(int x=0; x<SIZE; x++) {
		if(buffer[x]=='\n') {
			buffer[x]='\0';
			break;
		}
	}

	return(buffer); // buffer is decayed to a pointer to the 1st char
}

/* allocate memory to a new struct */
struct family *allocate(void)
{
	struct family *p;

	// malloc() returns a pointer to the allocated memory
	p = (struct family *)malloc( sizeof(struct family) * 1);
	if( p==NULL ) {
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	return(p);
}

struct family *add_record(struct family *first)
{
	// declare and initialization in same statement
	struct family *current = first;

	/* check to see if first record initialized */
	if( first == NULL ){
		current = allocate();
		first = current;
		fill(current);
	} else {
		// while next is not NULL, keep traversing the list
		// i.e. current is the last record in the list
		while(current->next) current = current->next;
		current->next = allocate();
		current = current->next;
		fill(current);
	}
	current->next = NULL;
	
	return first;
}


/* Delete a record */
struct family *delete_record(struct family *first)
{
	struct family *current = first;
	struct family *temp;
	// r = number of records, record = record index to delete by user prompt
	int r , record; 

	if( first == NULL ) {
		puts("Nothing to delete\n");
	} else {
		// output() returns the number of records
		r = output(first);

		/* prompt */
		printf("Remove record 1 to %d? ", r);
		record = strtod(input(), NULL); // prompt for record to delete
		if( record<1 || record>r ) {
			puts("Value out of range\n");
		} else {
			printf("Removing record %d...", record);
			/* test for first record */
			if( record == 1 ) {
				/* Check to see if first is the only record */
				if( first->next == NULL ) {
					free(first); // free memory
					first = NULL;
				} else {
					temp = first;
					first = first->next;
					free(temp);
				}
				puts("Done!\n");
			} else {
				/* record to delete isn't the first record */
				/* visit the previous record */
				while(record-2) {
					current = current->next;
					record--;
				}
				/* save the next record */
				temp = current->next;
				/* reset the current record pointer */
				current->next = temp->next;
				/* free the removed structure */
				free(temp);
				puts("Deleted\n");
			}
		}
	}

	return first;
}

/* fill the newly memory allocated struct */
void fill(struct family *s)
{
	char temp[SIZE];

	printf("Name: ");
	strcpy(s->name, input()); // s->name is decayed to a pointer
	printf("Relationship: ");
	strcpy(s->relationship, input());
	printf("Age: ");
	strcpy(temp, input() );
	s->age = strtod(temp, NULL);
	putchar('\n');
}

/* print the list, returns total number of records in list */
int output(struct family *s)
{
	int count = 0;

	/* check for empty list */
	if( s==NULL ) {
		puts("List is empty");
	} else { /* output all records */
		while( s!=NULL ) { // while not at the end of the list
			printf("%d: %s, your %s, is %d years old\n",
					count+1,
					s->name,
					s->relationship,
					s->age
				  );
			s = s->next;
			count++;
		}
	}
	putchar('\n');

	return(count);
}

/* save the linked list to file*/
void save(struct family *s)
{
	FILE *fp;
	int records; // records = number of records in list

	/* confirm that the list isn't empty */
	if( s==NULL ) {
		puts("List is empty\n");
		return;
	}

	/* count the number of records */
	records = output(s);
	printf("%d records to save...",records);
	
	/* open the file */
	fp = fopen(filename, "w");
	if( fp==NULL ) {
		fprintf(stderr, "Unable to create %s\n\n",filename);
		/* don't quit on this error */
		return;
	}

	/* save all the records */
	for(int x=0; x<records; x++ )
	{
		fwrite(s, sizeof(struct family), 1, fp);
		/* okay to change s here */
		s = s->next;
	}
	printf("%d written...", records);

	fclose(fp);

	puts("done!\n");
}

/* read linked list from a file and load to memory */
void open(struct family *s)
{
	FILE *fp;

	/* open the file */
	fp = fopen(filename, "r");
	if( fp==NULL ) {
		fprintf(stderr,"Unable to read from %s\n\n",filename);
		/* don't quit on this error */
		return;
	}
	printf("Opening file %s...", filename);

	/* read records from file sequentially, allocate to memory */
	int records = 1; // records is a counter
	while(1) {
		// file position is automatically incremented by fread() after each read
		// so next time fread() is called, it reads the next struct
		fread(s, sizeof(struct family), 1, fp);
		/* the NULL pointer is saved */
		if( s->next==NULL ) break;
		// first s is already allocated upon call to save()
		// so allocate memory from the 2nd s onwards
		s->next = allocate();
		s = s->next;
		records++;
	}
	printf("%d records read...",records);

	fclose(fp);

	puts("done!\n");
}

int main()
{
	struct family *first, *current, *temp;
	int done, r, record; // C has no built-in boolean type
	char command[SIZE];

	/* initialize first record to NULL */
	first = NULL;

	/* main menu and input loop */
	done = FALSE;
	puts("Family Database");
	while (!done) {
		/* initialize the current pointer to the start of the list */
		current = first;
		/* menu */
		puts("Menu:");
		puts("A - Add record");
		puts("D - Delete record");
		puts("L - List all records");
		puts("O - Open");
		puts("S - Save");
		puts("Q - Quit");
		printf("Choice: ");
		/* read input */
		strcpy(command, input() );
		/* process selection */
		switch(command[0])
		{
			/* add a record */
			case 'A':
			case 'a':
				first = add_record(first);
				break;
			/* delete a record */
			case 'D':
			case 'd':
				first = delete_record(first);
				break;
			/* list all records */
			case 'L':
			case 'l':
				output(first);
				break;
			/* open/retrieve existing records */
			case 'O':
			case 'o':
				first = allocate();
				open(first);
				break;
			/* save all records */
			case 'S':
			case 's':
				save(first);
				break;
			/* quit the program */
			case 'Q':
			case 'q':
				done = TRUE;
				puts("Bye!");
				break;
			/* something weird typed */
			default:
				puts("Unrecognized command");
		}
	}

	return(0);
}