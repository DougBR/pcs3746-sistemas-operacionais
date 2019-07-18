#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ARRAY_SIZE 1000

double big_array[ARRAY_SIZE];

int main()
{
	printf("Init starting\n");

	for (int i=0; i<ARRAY_SIZE; i++) {
		big_array[i] = (double)(i + 0.125);
	}


	printf("init finished\n");
	for (;;)
		sleep(1000);
	return 0;
}
