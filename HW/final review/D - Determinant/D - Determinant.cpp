#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
int det[8][8];
int determinant(int f[8][8], int n);

int main()
{
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &det[i][j]);
		}
	}
	
	printf("%d\n", determinant(det, n));
}

int determinant(int f[8][8], int n)
{
	
} 
