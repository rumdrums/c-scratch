#include <stdio.h>
#include <stdlib.h>

#define MAXROWS 20

void readinput(int *a[MAXROWS], int nrows, int ncols);
void computesums(int *a[MAXROWS], int *b[MAXROWS], int *c[MAXROWS], int nrows, int ncols);
void writeoutput(int *c[MAXROWS], int nrows, int ncols);

int main () {

	int row, nrows, ncols;

	int *a[MAXROWS], *b[MAXROWS], *c[MAXROWS];

	printf("Enter number of rows: ");
	scanf("%d", &nrows);
	printf("enter number of columns: ");
	scanf("%d", &ncols);

	for( row=0; row < nrows; ++row) {
		a[row] = (int *) malloc (ncols * sizeof(int));
		b[row] = (int *) malloc (ncols * sizeof(int));
		c[row] = (int *) malloc (ncols * sizeof(int));

	}

	printf("\n\nFirst table:\n");
	readinput(a, nrows, ncols);
	printf("\n\nSecond table:\n");
	readinput(b, nrows, ncols);
	
	computesums(a, b, c, nrows, ncols);
	
	printf("Sums:\n");
	writeoutput(c, nrows, ncols);

}

void readinput(int *a[MAXROWS], int nrows, int ncols) {

	int row, col;
	for (row = 0; row < nrows; ++row) {
		printf("\nEnter data for row number %2d\n", row + 1);
		for ( col = 0; col < ncols; ++col )
			scanf("%d", (a[row] + col));
	}
	return;
}

void computesums(int *a[MAXROWS], int *b[MAXROWS], int *c[MAXROWS], int nrows, int ncols) {

	int row, col;
	for (row = 0; row < nrows; ++row) 
		for (col = 0; col < ncols; ++col) 
			*(c[row] + col) = *(a[row] + col) + *(b[row] + col);
	return;
}

void writeoutput(int *c[MAXROWS], int nrows, int ncols) {

	int row, col;

	for ( row = 0; row < nrows; ++row) {
		for (col = 0; col < ncols; ++col )
			printf("%4d", *(c[row] + col));
		printf("\n");
	}
}
