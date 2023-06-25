#include <stdio.h>
#include <stdlib.h>

/* allocate pointer and assign text */ 
void get_input(char **b) {
	*b = (char *)malloc( sizeof(char) * 16 );
	if( *b==NULL ){
		fprintf(stderr,"Unable to allocate buffer\n");
		exit(1);
	}

	fgets(*b, 16, stdin);

	/* remove the newline */
	for( int x=0; x<16; x++ ) {
		if( *(*b+x)=='\n' ) {
			*(*b+x)='\0'; 
			break;
		}
	}
}

/* create the array of pointers and output the results */
int main() {
	char **names; // char *names[3];

	names = (char **)malloc( sizeof(char *) * 3 );
	if( names==NULL ) {
		fprintf(stderr,"Unable to allocate array\n");
		exit(1);
	}

	/* read the names */
	for(int x=0; x<3;x++ ) {
		printf("Name #%d: ",x+1);
		get_input( names+x ); // &names[x]
	}

	/* output the results */
	for( int x=0; x<3;x++ ) printf("%s\n", *(names+x)); // names[x]

	return(0);
}
