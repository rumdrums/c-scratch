#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>


int main() {

	char *root_path = "/root";
	DIR *dir;
	struct dirent *entry;
	struct stat s;

	if(!(dir = opendir(root_path)))
		printf("Failed to open.\n");

	while(entry = readdir(dir)) {
	    char path[1024];
	    long len = snprintf(path, sizeof(path), "%s/%s", root_path, entry->d_name); 	
	    path[len] = '\0';
	    /*printf("%s\n",entry->d_name); */
	    lstat(path, &s);
	    /*printf("S_ISDIR(s.st_mode) == 0: %d\n",S_ISDIR(s.st_mode) == 0); */
	    printf("Error: %s\n",strerror(errno));
	    /*printf("lstat(entry->d_name, &s) ==: %d\n",lstat(entry->d_name, &s));*/
	}
	
	return 0;
}	


