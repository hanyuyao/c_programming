#include <stdio.h>
#include <stdlib.h>

int compare_int(const void* a, const void* b)
{
	const int* ai = (const int*)a;
	const int* bi = (const int*)b;
	return *ai-*bi;
} 

int main()
{
	int *a;
	char *b;
	int i, j;
	int size, row, col;
	int index;
	printf("enter size of 1D array:\n");
	scanf("%d", &size);
	
	a = (int*) malloc(size*sizeof(int));
	if(a == NULL){
		printf("fail");
		exit(EXIT_FAILURE);
	}
	
	for(i = 0; i < size; i++){
		a[i] = rand()%10;
		printf("%d ", a[i]);
	}
	printf("\n");
	
	qsort(a, size, sizeof(int), compare_int);
	
	for(i = 0; i < size; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	free(a);
	
	
	printf("enter length for a rectangle:\n");
	scanf("%d", &row);
	printf("enter width for a rectangle:\n");
	scanf("%d", &col);
	b = (char*)malloc(row*col*sizeof(char));
	if(b == NULL){
		printf("fail");
		exit(EXIT_FAILURE);
	}	
	
	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
			index = i*col + j;
			b[index] = '*';
		}
	}
/*	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
			printf("%c", b[i*col + j]);
		}
		printf("\n");
	}                       */
	
	for(i = 0; i < col; i++)
		printf("%c", b[i]);
	printf("\n");
	for(i = 1; i < row-1; i++){
		printf("%c", b[i*col]);
		for(j = 0; j < col-2; j++){
			printf(" ");
		}
		printf("%c", b[i*col + col-1]);
		printf("\n");
	}
	for(j = 0; j < col; j++)
		printf("%c", b[(row-1)*col + j]);
	
	free(b);
	return 0;
}
