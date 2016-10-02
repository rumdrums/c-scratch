#include <stdio.h>

void print_static();

int main() {

	int i = 0;

	for(i;i<10; i++) 
		print_static();

}

void print_static() {

	static int i = 0;
	printf("%d\n", i);
	i++;
}


