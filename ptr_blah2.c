#include <stdio.h>

/* lesson here: 
	... but you can't pass the pointer itself if the function
	is not expecting it */

/*
ptr_blah2.c: In function ‘main’:
ptr_blah2.c:12:7: warning: passing argument 1 of ‘func’ makes integer from pointer without a cast
  func(ptr); 
       ^
ptr_blah2.c:7:6: note: expected ‘int’ but argument is of type ‘int *’
 void func(int);
*/

void func(int);

int main() {
	int i=1;
	int *ptr = &i;
	func(ptr);
	printf("%d\n",*ptr);
}

void func(int i) {
	int j = 10;
	printf("%d\n",i);
	i = j;
}
