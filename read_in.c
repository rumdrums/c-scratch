#include <stdio.h>
#include <unistd.h>

# define MAX_READ 200

int main() {

	char buffer[MAX_READ+1];
	ssize_t numRead;

	printf("Enter somethin: \n");

	numRead = read(STDIN_FILENO, buffer, MAX_READ);
	if(numRead == -1) {
		printf("Can't read -- aargh\n");
	}
	buffer[numRead] = '\0';
	printf("You input: %s\n", buffer);
}
