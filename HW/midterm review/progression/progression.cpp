#include <stdio.h>

int main()
{
	int a, b, c;
	int f, l;
	scanf("%d %d %d", &a, &b, &c);
	if(2*b == a+c){
		f = 2*a - b;
		l = 2*c - b;
	}
	else{
		f = a/(b/a);
		l = c*(c/b);
	}
	printf("%d %d", f, l);
	return 0;
	

 } 
