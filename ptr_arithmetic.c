#include <stdio.h>

int main() {

	int x[] = {1,2,3,4,5,6,7,8,9,10};
	int *px = x;
	int *py = &x[9];
	int i;

	printf("&x: %d, x: %d", &x[0], x[0]);
	printf("px: %d\n", *px);
	printf("px+1: %d\n", px+1);
	
	for(i = 0; i<10; i++) {
		printf("*(px + %d): %d\n", i,*(px+i));
	}
	
	printf("py: %d, *py: %d\n", py, *py); 
	printf("py - px: %d\n", (py-px)); 
}
