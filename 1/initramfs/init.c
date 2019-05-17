#include <stdio.h>
#include <sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

void panic(const char *msg)
{
	fprintf(stderr, "%s: %s (errno = %d)\n", msg, strerror(errno), errno);
	exit(-1);
}

int main()
{
pid_t pid = fork();

	if (pid == -1 ) {
    panic("fork failed");
   }
  else if (pid){
		/* Parent code */
		while (1) {
			printf("1\n");
		}
		return 0;
    
	} else {
		/* Child code */
		execve("child", NULL, NULL);
	}
}
