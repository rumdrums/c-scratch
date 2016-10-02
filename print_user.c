#include <stdio.h>
#include <pwd.h>

int main() {

	struct passwd *pwd;

	pwd = getpwnam("james");
	printf("%s\n", pwd->pw_name);
	printf("%s\n", pwd->pw_passwd);
	printf("%d\n", pwd->pw_uid);
	printf("%d\n", pwd->pw_gid);
	printf("%s\n", pwd->pw_gecos);
	printf("%s\n", pwd->pw_dir);
	printf("%s\n", pwd->pw_shell);
}

