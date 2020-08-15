#include <stdio.h>
#include "function.h"
int get_sum(int** int_2D_array, int length, int width)
{
    int i, j;
    int sum = 0;
    for(i = 0; i < length; i++){
    	for(j = 0; j < width; j++){
    		sum = sum + int_2D_array[i][j]; 
		}
	}
	return sum;
}
