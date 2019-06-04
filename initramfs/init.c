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
      printf("running init process");
      while(1){
        sleep(10);
        kill(pid, SIGFPE);
      }
		} else {
      printf("running signal handling process with PID:%d", pid);
			execve("signal_bypassing", NULL, NULL);
		}

	return 0;
}
