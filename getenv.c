#define _GNU_SOURCE
#include <stdio.h>

extern char **environ;

int
main() {

	char **ep;
	for(ep=environ; *ep != NULL; ep++)
		printf("%s\n",*ep);
}
