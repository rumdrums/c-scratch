#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>


int main(int argc, char *argv[]) {

	char *path = argv[1];
	struct stat *s;

	if(lstat(path, s) == -1)
		printf("Error\n");

	printf("%lld\n",s->st_size);
	return 0;
}
