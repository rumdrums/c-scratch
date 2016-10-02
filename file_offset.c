#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#define MAXREAD 2

int main() {

	char buf[MAXREAD+1];
	char *file = "./test_file";
	int fd;
	ssize_t numRead;
	off_t offset;

	fd = open(file, O_RDONLY);
	if ( fd == 1) {
		printf("Error opening file\n");
		exit(1);
	}
	
	while ((numRead = read(fd, buf, MAXREAD)) > 0) {
		buf[numRead] = '\0';
		printf("%s", buf);
		if ( numRead == 1 )
			exit(0);
		offset = lseek(fd, -1, SEEK_CUR);
		if (offset == -1) {
			exit(1);
		}
		
	}	
	printf("\n");
	close(fd);	
}
