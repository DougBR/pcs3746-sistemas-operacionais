#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ARRAY_SIZE (16 * 1024 * 1024) / 3

char big_array[ARRAY_SIZE];
int lower = 32;
int upper = 126;

int main()
{
	printf("large starting\n");

	while (1) {
		for (int i=0; i<ARRAY_SIZE; i++) {
			big_array[i] = (char) ((rand() % (upper - lower + 1)) + lower);
			if (i % 1000 == 0)
				getchar();
		}
	}

	printf("large finished\n");
	return 0;
}
