#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ARRAY_SIZE 8*1024*1024/(3*sizeof(double))

double big_array[ARRAY_SIZE];

int main()
{
	int i = 0;
	printf("large starting\n");

	while(1){
		big_array[i++] = (double) i*1.125;
		if (i%1000 == 0)
			getchar();
		else if (i == ARRAY_SIZE)
			i = 0;
	}

	printf("large finished\n");
	return 0;
}
