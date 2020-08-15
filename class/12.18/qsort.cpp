#include <stdio.h>
#include <stdlib.h>

int compare_int (const void *a, const void *b)
{
    const int *va = (const int *) a;    //把a轉成const int*的型別 
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

//qsort(陣列名稱, 陣列大小, sizeof(型別), compare function) 
                        // string : 大小*sizeof(char) 
 
