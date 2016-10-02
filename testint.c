#include <stdio.h>

#define MAX 4294967297

main() {

	int x = 0;

	while ( x < MAX ) {

		printf("%d ",x);
		x+=10000;
	}
}

	
