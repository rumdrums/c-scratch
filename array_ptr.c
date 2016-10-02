#include <stdio.h>

int main() {
	static int x[10] = {0,1,2,3,4,5,6,7,8,9};
	int i;
	for(i=0; i<=9; ++i)  {
		 // printf("i = %d, x[i] = %d, &x[i] = %X\n", i, x[i], &x[i]);
		printf("i = %d, x[i] = %d, &x[i] = %X\n", i, x[i], x + i);
	}
}
