#include <stdio.h>

/* lesson here: 
	you can pass the value that the pointer is pointing to,
	to a function not expecting a pointer, obviously */

void func(int);

int main() {
	int i=1;
	int *ptr = &i;
	func(*ptr);
	printf("%d\n",*ptr);
}

void func(int i) {
	int j = 10;
	printf("%d\n",i);
	i = j;
}
