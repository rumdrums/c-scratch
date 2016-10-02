#include <stdio.h>

void take_array(int a[]);

int main() {

	int a[] = {0,1,2,3,4,5,6,7,8,9};
	int i;

	take_array(a);

	for( i=0; i < 10; i++ ) {
		printf("%d\n",a[i]);
	}	

}

void take_array(int a[]) {

	int i;
	
	for ( i=0; i < 10; i++ ) {
		a[i] = 0;	
	}
}

