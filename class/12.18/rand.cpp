#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	int array[10];
	double darray[10];
	
	for(i = 0; i < 10; i++){
		array[i] = rand()%10;    //restrict rnadom number to 10
		darray[i] = (double)rand()/RAND_MAX;
	}
	for(i = 0; i < 10; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
	
	
	for(i = 0; i < 10; i++){
		printf("%.3f ", darray[i]);
	}
}

// rand() "randomly" generate a decimal number
// remember to include <stdlib.h>
