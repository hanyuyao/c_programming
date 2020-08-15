#include <stdio.h>

int main()
{
	int *ptrArr[10];
	int dataArr[10]={0};
	int i;
	for(i = 0; i < 10; i++){
		ptrArr[i] = &dataArr[i];
	}
	*ptrArr[0] = 8;
	for(i = 0; i < 10; i++){
		printf("prtArr[%d] = %d\n", i, *ptrArr[i]);
	}
	for(i = 0; i < 10; i++){
		printf("dataArr[%d] = %d\n", i, dataArr[i]);
	}
	return 0;
} 
