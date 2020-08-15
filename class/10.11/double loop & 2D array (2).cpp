#include <stdio.h>
int table[10000][10000];
int main()
{
	int i, j;
	for(i=0; i<10000; i++)
		for(j=0; j<10000; j++)
			table[i][j]=i*j;
	
	int a, b;
	scanf("%d %d", &a, &b);
	
	for(i=0; i<a; i++){
		for(j=0; j<b; j++)
			printf("%3d", table[i][j]);
	printf("\n");
	}
	
 } 
