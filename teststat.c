#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>


int main() {

	char *path = "/root/rsync_3.0.9-4.diff.gz";
	struct stat s;

	if(lstat(path, &s) == -1)
		printf("Error\n");

	return 0;
}
