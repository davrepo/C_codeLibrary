#include <stdio.h>
struct point{
    int x;
    int y;
};

void printPoint(struct point pt);
void readPoint(struct point * ptr);
void printLine(struct point *ptr);

int main(void) {
    struct point line[2];
    for (int i=0; i<2; i++) { readPoint(&line[i]); }
    printLine(line);
	return 0;
}

void readPoint(struct point * ptr) {
    printf("x-coordinate: ");
    scanf("%d", &ptr->x);
    printf("y-coordinate: ");
    scanf("%d", &ptr->y);
}

void printLine(struct point *ptr) {
    int i;
    for (i=0; i<2; i++) { printPoint(ptr[i]); }
}

void printPoint(struct point pt){
    printf("(%d, %d)\n", pt.x, pt.y);
}

