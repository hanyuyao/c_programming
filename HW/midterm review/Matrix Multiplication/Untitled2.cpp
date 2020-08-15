#include <stdio.h>

int main()
{
	int N, M, P;
	while(scanf("%d %d %d", &N, &M, &P) != EOF){
	long long int a[101][101];
	long long int b[101][101];
	long long int c[101][101]={0};
	int n, m, p;
	
	
	for(n = 0; n < N; n++){
		for(m = 0; m < M; m++)
			scanf("%lld", &(a[n][m]));
	}
	
	for(m = 0; m < M; m++){
		for(p = 0; p < P; p++)
			scanf("%lld", &(b[m][p]));
	}
	
		
	
	for(n=0; n<N; n++){
		for(p=0; p<P; p++){
			c[n][p]=0;                      //Âk¹s 
			for(m=0; m<M; m++)
				c[n][p] += a[n][m] * b[m][p]; 
		}
	}
	
	for(n=0; n<N; n++){
		for(p=0; p<P; p++){ 
			printf("%lld", c[n][p]);
				if(p != (P-1))
					printf(" ");
				else
					printf("\n");
		}
					
	}
	
	printf("\n");
	
	}
	
}
