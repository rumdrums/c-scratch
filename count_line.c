# include <stdio.h>

main() {
	int nl, c = 0;

	while ((c=getchar()) != EOF) {
		
		if ( c == '\n') {
			nl++;
		}
			
		printf("%d\n",nl);
	}
}

		
