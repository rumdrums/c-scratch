#include <stdio.h>

int main() {

	int x = 10;
	int *px = &x;
	int i;

	printf("x: %d", x);
	printf("px: %d\n", *px);
	printf("px+1: %d\n", px+1);
	
	for(i = 0; i<100; i++) {
		printf("px+i: %d\n", (px+i));
		printf("*(px+i): %d\n", *(px+i));
	}
}
