#include <stdio.h>
#include <stdlib.h>

int compare_int (const void *a, const void *b)
{
    const int *va = (const int *) a;    //��a�নconst int*�����O 
    const int *vb = (const int *) b;
    return *va-*vb;       /*if a>b return positive number
	                        if a<b return negative number
							if a=b return 0    */
}

int main()
{
	int i, j;
	int array[10];
	int x;
	scanf("%d", &x);
	
	for(i = 0; i < 10; i++){
		array[i] = rand()%x;     //%x: restrict to x
	}
	
	for(i = 0; i < 10; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
	
	qsort(array, 10, sizeof(int), compare_int);
	for(i = 0; i < 10; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

//qsort(�}�C�W��, �}�C�j�p, sizeof(���O), compare function) 
                        // string : �j�p*sizeof(char) 
 
