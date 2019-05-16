#include <stdio.h>
#include <sys/types.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	if (fork() != 0) {
		/* Parent code */
		while (1) {
			printf("1\n");
		}
		return 0;
	} else {
		/* Child code */
		execve("./child.o", NULL, NULL);
	}
}
