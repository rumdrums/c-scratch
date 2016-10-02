#include <stdio.h>

void take_array(int *a);

int main() {

	int a[] = {0,1,2,3,4,5,6,7,8,9};
	int i;

        printf("Before func call: ");
        for( i=0; i < 10; i++ ) {
                printf("%d ",a[i]);
        }       
        printf("\n");

	take_array(a);

	printf("After func call: ");
	for( i=0; i < 10; i++ ) {
		printf("%d ",a[i]);
	}	
	printf("\n");

}

void take_array(int *a) {

	int i;
	int j = 9;
	
	for ( i=0; i < 10 ; i++ ) {
		/* Why the FUCK can I do either of these ? */
		/* *(a + i) = 0; */
		a[i] = j;	
		j--;
	}
}

