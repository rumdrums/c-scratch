#include <stdio.h>

void func1(int x);

main() {
	int x = 0;
	int *px = &x;
	func1(*px);
	printf("main x: %d\n",x);
	*px = *px + 1;
	printf("main x: %d\n",x);
}


void func1(int x) {
	x = x + 1;
	printf("func 1 x: %d\n",x);
}
