#define _BSD_SOURCE
#define _XOPEN_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <limits.h>
#include <stdlib.h>
#include <shadow.h>
#include <errno.h>
#include <crypt.h>
int main() {

	char *username, *password, *encrypted, *p;
	struct passwd *pwd;
	struct spwd *spwd;
	size_t len;
	int authOk = 0;

	/* get max length of password or set it
		to something big enough*/
	long lnmax = sysconf(_SC_LOGIN_NAME_MAX);
	if (lnmax == -1)
		lnmax = 256;	
		
	username = malloc(lnmax);
	if (username == NULL) {
		printf("malloc\n");	
		exit(1);
	}
	printf("Username: ");
	fflush(stdout);
	if (fgets(username, lnmax, stdin) == NULL) {
		exit(2);
	}
	
	len = strlen(username);
	if (username[len-1] == '\n')
		username[len-1] = '\0';

	pwd = getpwnam(username);
	if (pwd == NULL) {
		printf("Couldn't get password");
		exit(3);
	}

	spwd = getspnam(username);
	if (spwd == NULL && errno == EACCES) {
		printf("No permission to read shadow file\n");
		exit(4);
	}	

	if (spwd != NULL)  {
		/* set pwd->pw_passwd to shadow file's encrypted pass entry */
		pwd->pw_passwd = spwd->sp_pwdp; 
	}
	
	/* get user's password from promp */
	password = getpass("Password: ");
	
	/* encrypt pass and erase cleartext version immediately */
	encrypted = crypt(password, pwd->pw_passwd);
	for ( p = password; *p != '\0'; )
		*p++ = '\0';
	
	if ( encrypted == NULL) {
		printf("crypt failure");
		exit(5);
	}

	authOk = strcmp(encrypted, pwd->pw_passwd) == 0;
	if ( !authOk ) {
		printf("Incorrect password\n");
		exit(6);
	}

	printf("Successfully authenticated: UID=%ld\n", (long) pwd->pw_uid);		

}
	
