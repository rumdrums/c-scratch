#include <stdio.h>

void count();

int main() {

	int i = 0;
	for(i=0; i<10; i++)
		count();
}

void count() {

	static int i = 100;
	i++;
	printf("%d\n", i);
}

