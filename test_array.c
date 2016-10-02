#include <stdio.h>

void func(char *a);

int main() {

	char a[7] = "string";
	printf("%s\n",a);
	func(a);
	printf("%s\n",a);
}

/* It's weird -- any combination of the commented/uncommented stuff works
 * and effectively modifies the array, which is passed by reference, not value */
//void func(char *a) {
void func(char a[]) {
	*a = 'b';
	// a[0] = 'b';
	printf("%s\n",a);
}
	
