#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 12

void reorder(int n, char *x[]);

int main() {

	int i, n = 0;
	char *x[10];

	printf("Enter each string on a line below\n");
	printf("Type \'END\' when finished\n");

	// read in list of strings:
	do {
		// allocate memory:
		x[n] = (char *) malloc (SIZE * sizeof(char));

		printf("string %d: ", n+1);
		scanf("%s", x[n]);
	} 
	while ( (strcmp(x[n++], "END")) && (n<10) );

	// reorder list of string:
	reorder(--n, x);

	// display reordered stuff:
	printf("Reordered list of strings: \n");
	for(i=0; i<n; ++i)
		printf("string %d: %s\n", i+1, x[i]);
	
}

void reorder(int n, char *x[]) {

	char *temp;
	int i, item;

	for(item = 0; item < n-1; ++item) {

		for ( i = item+1; i<n; ++i) {

			if (strcmp(x[item], x[i]) > 0) {
				// interchange strings:
				temp = x[item];
				x[item ] =  x[i];
				x[i] = temp;
			}
		}
	}
	return;
}	
