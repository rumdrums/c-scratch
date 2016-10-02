#include <stdio.h>

int main() {

	int x;
	scanf("%d", &x);

	printf("allocating array of size %d\n", x);

	int array[x];
	
	int i;
	for(i=0; i<x; i++) {
		array[i] = i;
		printf("array[%d] = %d\n", i,array[i]);
	}

}	
