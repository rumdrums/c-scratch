#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/* compiled with:
cc interest.c -o interest -lm
*/

/* prototypes: */
void table( double (*pf)(double i, int m, double n), double a, int m, double n );
double md1( double i, int m, double n);
double md2( double i, int m, double n);
double md3( double i, int m, double n);

int main() {
	int m; 		/* compounding periods per year */
	double n;	/* number of years */
	double a; 	/* amount of each monthly payment */
	char freq; 	/* frequency of compounding indicator */

	/* enter input data */
	printf("\nFuture value of a series of Monthly Depositis\n\n");
	printf("Amount of each monthly payment: ");
	scanf("%lf", &a);
	printf("Number of years: ");
	scanf("%lf", &n);
	
	/* enter frequency of compounding */
	do {
		printf("Frequency of compounding (A, S, Q, M, D, C): ");
		scanf("%1s", &freq);
		freq = toupper(freq);
		if (freq == 'A') {
			m = 1;
			printf("\nAnnual compounding\n");
		}
		else if (freq == 'S') {
			m = 2;
			printf("\nSemi-annual compounding\n");
		}
		else if (freq == 'Q') {
			m = 4;
			printf("\nQuarterly compounding\n");
		}
		else if (freq == 'M') {
			m = 12;
			printf("\nMonthly compounding\n");
		}
		else if (freq == 'D') {
			m = 365;
			printf("\nDaily compounding\n");
		}
 		else if (freq == 'C') {
			m = 0;
			printf("\nContinuous compounding\n");
		}	
		else
			printf("\nERROR -- please repeat\n\n");
		
	} while (freq != 'A' && freq != 'S' && freq != 'Q' 
			&& freq != 'M' && freq != 'D' && freq != 'C');

	/* do calculations */
	if ( freq == 'C' )
		table(md3, a, m, n);
	else if ( freq == 'D' )
		table(md2, a, m, n);
	else
		table(md1, a, m, n);

}	
	
void table( double (*pf)(double i, int m, double n), double a, int m, double n ) {
	/* first arg is pointer to another function */

	int count;
	double i; 	/* annual interest rate */
	double f;	/* future value */

	printf("\n Interest rate     Future Amount\n\n");
	for ( count = 1; count <= 20; ++count ) {
		i = .01 * count;
		f = a * (*pf)(i, m, n);
		printf("%2d     %.2f\n", count, f);
	}
	return;
}

double md1(double i, int m, double n) {
	/* monthly deposits, periodic compounding */

	double factor, ratio;
	
	factor = 1 + i/m;
	ratio = 12 * (pow(factor, m*n) - 1 ) / i;
	return(ratio);
}

double md2(double i, int m, double n) {
	/* monthly deposits, daily compounding */

	double factor, ratio;
	
	factor = 1 + i/m;
	ratio = (pow(factor, m*n) - 1) / (pow(factor, m/12) - 1);
	return(ratio);
}

double md3(double i, int dummy, double n) {
	/* monthly deposits, continuous compounding */

	double ratio;

	ratio = (exp(i*n) -1 ) / (exp(i/12) - 1);
	return(ratio);
}

	
