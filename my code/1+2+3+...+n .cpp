#include <stdio.h>

int sum(int n)
{
	if(n == 1)
		return 1;
	else 
		return n + sum(n-1);
}
int main()
{
	printf("Please enter a interger n:\n");
	int x;
	scanf("%d", &x);
	printf("The sum of 1+2+3+...+%d is %d.", x, sum(x));
	return 0;
}
