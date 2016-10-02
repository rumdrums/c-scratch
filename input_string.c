#include <stdio.h>

int main() {
	char line[80];
	scanf(" %[abc]", line);
	printf("%s\n", line);
}
