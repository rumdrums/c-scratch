#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h> /* for exit() */

#define BUF_SIZE 1024

/* this sort of works for capturing STDIN or STDOUT of another 
 * terminal session, but it sort of breaks that terminal's session
 * in the process */

int 
main(int argc, char *argv[]) {

	size_t len;
	off_t offset;
	int fd;
	ssize_t numRead;

	char buf[BUF_SIZE];

	/* check for proper input */
	if ( argc < 2 || strcmp(argv[1],"--help") == 0 ) {
		printf("\n\n\tUsage: %s <file name>\n\n\n",argv[0]);
		exit(1);
	}
	
	fd = open( argv[1], O_RDONLY);
	if (fd == -1) {
		printf("Error opening file\n");
		exit(1);
	}

	/* 
		1) Read file buf full or nothing left
		2) Print output
		3) Return to beginning of file
		4) Go to 1
	*/
	
	while ( 1 ) {	

		while( (numRead = read(fd, buf, BUF_SIZE)) > 0 ) {
			printf("\n%s\n", buf);
		}
	
		printf("End of file encountered, starting over ...\n");
		
		offset = lseek(fd, 0, SEEK_SET);
		if ( offset == -1 ) {
			printf("Error resetting offset\n");
			exit(1);
		}
	}
		 
}
