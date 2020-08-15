#include <stdio.h>



int main()
{
	int n;
	double a[5][5];
	double x[5];
	double p;
	double next[5];
	int i, j;
	int count=0;
	double A, B;
	int status = 1;
	int T, k;
	scanf("%d", &T);
	
	for(k=0; k<T; k++){
		status = 1;
		count = 0;
		A = 0;
		B = 0;
		
		scanf("%d", &n);
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				scanf("%lf", &a[i][j]);
			}
		}
		for(i = 0; i < n; i++){
			scanf("%lf", &x[i]);
		}
		scanf("%lf", &p);
	
		do
		{
			for(i=0; i<n; i++)
				next[i]=0;
			
			for(i=0; i<n; i++){
				for(j=0; j<n; j++){
					next[i] += a[i][j]*x[j];
				}
			}
			count++;
			
			for(i=0; i<n; i++)
				x[i] = next[i];
				
			A = next[0];	
			if(A == B){
				status = 0;
				break;
			}
			if(A != B){
				B = A;
			}
			if(count == 100000){
				status = 0;
				break;
			}
		}while(next[0] > p);
	
		if(status){
			printf("%d\n", count);
		}
		else if(!status)
			printf("Never\n");
	}
}
