#include <stdio.h>

/* lesson here: it's easy to change
the value of the variable a pointer points to */

void func(int*);

int main() {
	int i=1;
	int *ptr = &i;
	func(ptr);
	printf("%d\n",*ptr);
}

void func(int *i) {
	int j = 10;
	printf("%d\n",*i);
	*i = j;
}
