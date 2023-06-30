#include <stdio.h>

struct student{
	char name[5];
	int birthYear;
};
void printStudent(struct student);
void readStudent(struct student *);

int main(void) {
    struct student me;
    readStudent(&me);
    printStudent(me);
	return 0;
}

void readStudent(struct student *studptr) {
    printf("Name: ");
    scanf("%s", (*studptr).name); // studptr->name
    printf("Birth year: ");
    scanf("%d", &(*studptr).birthYear); // &studptr->birthYear
}

void printStudent(struct student stud) { // pass a copy of the struct
    printf("Name: %s\n", stud.name);
	printf("Year of birth: %d\n",stud.birthYear);
}

