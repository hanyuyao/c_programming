#include <stdio.h>

int main()
{
	int i, j;
	double *p[101];
	double data[101];
	int n;
	int k, l;
	
	for(i = 0; i < 101; i++)
		p[i] = &data[i]; 
	
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d %d", &k, &l);
		p[k] = p[l];
	}
	
	
	double x;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d %lf", &k, &x);
		*p[k] = x;
	}
	
	scanf("%d", n);
	for(i = 0; i < n; i++){
		scanf("%d", &k);
		printf("%lf", data[k]);
	}
}
