#include <stdio.h>

int main() {

	char *x[2];
	int i;

	x[0] = "hey";
	x[1] = "there";
	
	for(i=0; i<2; i++) {
		printf("x = %p\n",x);
		printf("(x+i) = %p\n",(x+i));
		printf("*(x+i) = %s\n",*(x+i));
		printf("x[i] = %s\n",x[i]);
	}
}
