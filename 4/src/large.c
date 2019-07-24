#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ARRAY_SIZE 700000

double big_array[ARRAY_SIZE];

int main()
{
	printf("large starting\n");

	for (int i=0; i<ARRAY_SIZE; i++) {
		big_array[i] = (double)(i + 0.125);
        if (i % 1000 == 0)
            getchar();
	}


	printf("large finished\n");
	return 0;
}
