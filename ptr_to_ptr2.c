#include <stdio.h>

int g = 1;

void reassign(int*);

int main() {
	int l = 2;
	int *ptr = &l;
	printf("\nValue of g: %d\n", g);
	printf("Value of &g: %p\n", &g);
	printf("Value of l: %d\n", l);
	printf("Value of &l: %p\n", &l);
	printf("Initial value of ptr: %p\n",ptr);
	printf("Initial value of *ptr: %d\n",*ptr);
	printf("\nPassing &ptr to func ...\n\n");
	reassign(ptr);
	printf("\nNew value of ptr: %p\n",ptr);
	printf("Value of l: %d\n\n",l);
	return 0;
}

void reassign(int *ppInt) {
	*ppInt = g;
}
