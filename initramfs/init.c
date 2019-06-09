#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void panic(const char *msg)
{
	fprintf(stderr, "%s: %s (errno = %d)\n", msg, strerror(errno), errno);
	exit(-1);
}

int main()
{
    pid_t pid = fork();

	if (pid == -1) {
		panic("fork");
	} else if (pid) {
		while(1){
			//printf("[init] Running init process. Sending kill signal to process %d.\n", pid);
			sleep(10);
			//kill(pid, SIGFPE);
		}
	} else {
      		printf("[init] Running signal handling process.\n");
			execve("signal_bypassing", NULL, NULL);
	}

	return 0;
}
