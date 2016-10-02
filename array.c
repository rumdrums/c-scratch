#include <stdio.h>

# define SIZE 5

main() {

	int a[SIZE] = { 1,2,3,4,5} ;
	int (*p)[SIZE] = &a;
	int i = 0;
	for(i=0; i<SIZE; i++)
		printf("%d\n",a[i]);
}
