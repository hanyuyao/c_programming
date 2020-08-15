#include <stdio.h>

int main()
{
	int i, j;
	int a[10][10];
	for (i=0; i<10; i++){
		for(j=0; j<10; j++)
		{
		a[i][j] = i*j;
		printf("%3d",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	for(i=0; i<10; i++){
		for(j=0; j+i<9; j++){
			printf("  ");
		}
		for(j=i; j<10; j++){
			printf("%3d", a[i][j]);
		}
	printf("\n");
	}
}
