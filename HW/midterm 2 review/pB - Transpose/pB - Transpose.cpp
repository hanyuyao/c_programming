#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

void Transpose( int* row, int* col, int matrix[][500] )
{
	int temp;
	int temp_matrix[500][500];
	int i, j;
	
	for(i = 0; i < *row; i++){
		for(j = 0; j < *col; j++){
			temp_matrix[i][j] = *(*(matrix + j)+i);
			*(*(matrix+j)+i)= *(*(matrix + i)+j);
			*(*(matrix + i)+j) = temp_matrix[i][j];
		}
	}
	
	temp = *row;
	*row = *col;
	*col = temp;
}

#endif
