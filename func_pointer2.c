#include <stdio.h>

void func1(int u, int v);
void func2(int *pu, int *pv);

int main() {

	int u = 1;
	int v = 3;
	int *pu = &u;
	int *pv = &v;
	
	printf("Before calling func1: u = %d, v = %d\n", u, v);
	func1(u, v);
	printf("After calling func1: u = %d, v = %d\n", u, v);
	printf("Before calling func2: u = %d, v = %d\n", u, v);
	// func2(&u, &v);
	func2(pu, pv);
	printf("After calling func2: u = %d, v = %d\n", u, v);
		
}

void func1(int u, int v) {

	u = 0;
	v = 0;
	printf("Within func1: u = %d, v = %d\n", u, v);
	return;
}

void func2(int *pu, int *pv) {

	*pu = 0;
	*pv = 0;
	printf("Within func2: *pu = %d, *pv = %d\n", *pu, *pv);
	return;
}

