#include <stdio.h>
#include <string.h>
#include <ctype.h>


int g(int y){
	if(y > 100)
		return y;
	y = y*g(y*y);	
}
	
	
int main()
{
	int a;
	scanf("%d", &a);
	printf("%d", g(a));
}
