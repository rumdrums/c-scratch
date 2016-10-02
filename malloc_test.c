#include <stdio.h>

#define DATA_SIZE (16*1024)

void func();

int main() {

	unsigned long int i;
	for(i=0; i<10000000000; i++) func;
}

void func() {

	char *data_ptr;
	data_ptr = malloc(DATA_SIZE);
}

