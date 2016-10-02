#include <stdio.h>
#include <sys/statvfs.h>

int main() {

	const char *path = "/";
	struct statvfs buf;
	statvfs(path, &buf);
	printf("%d\n", buf.f_bsize);

	return 0;
}
	
