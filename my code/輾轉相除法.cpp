#include <stdio.h>

int gcd (int m, int n)
{
	if(n==0)
		return m;
	else 
		gcd(n, m%n);
 } 
 
 int main()
 {
 	int a, b;
 	scanf("%d %d", &a, &b);
 	printf("%d", gcd(a, b));
 }
