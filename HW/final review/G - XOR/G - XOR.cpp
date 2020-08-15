#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	int i, j, k;
	int count;
	int record[100000][21];
	scanf("%d", &n);
	int* in = (int*)malloc(n*sizeof(int));
	for(i=0; i<n; i++){
		scanf("%d", &in[i]);
	}
	for(i=0; i<21; i++){
		for(j=0; j<n; j++){
			record[j][i] = in[j]%2;
			in[j] = in[j]/2;
		}
	}
	
	for(i=0; i<21; i++){
		count=0;
		for(j=0; j<n; j++){
			count += record[j][i];
		}
		if(count > n/2){
			for(k=0; k<n; k++){
				record[k][i] = record[k][i]^1;
			}
		}
	}
	
	int ans[21];
	for(i=0; i<21; i++){
		for(j=0; j<n; j++){
			ans[i] += record[j][i];
		}
	}
	int sum=0;
	
	for(i=0; i<21; i++){
		for(j=0; j<i; j++){
			sum += ans[i]*2;
		}
	}
	sum += ans[0];
	printf("%d\n", sum);
} 

