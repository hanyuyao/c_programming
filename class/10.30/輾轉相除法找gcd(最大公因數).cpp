#include <stdio.h>

int gcd(int m, int n){
	if(n==0) return m;        //or  if(m%n == 0) return n;
	return gcd(n, m%n);
}

int main()
{
	int i, j;
	scanf("%d %d", &i, &j);
	printf("%d", gcd(i,j));
	return 0;
}
