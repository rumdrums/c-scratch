#include <stdio.h>

void print_ptr(char*);

int main() {

	char *a = "hey there";
	print_ptr(a);
	return 0;
}

void print_ptr(char *ptr) {
	printf("ptr %%s: %s\n",ptr);
	printf("ptr %%p: %p\n",ptr);
	printf("*ptr %%p (actually printing hex value of 1st letter): %p\n",*ptr);
	printf("*ptr %%c: %c\n",*ptr);
}
