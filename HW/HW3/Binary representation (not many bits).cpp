#include <stdio.h>

int main()
{
	unsigned long long input;
	unsigned long long i, j;
	unsigned long long output=0;
	scanf("%llu", &input);
	
	for(i=1; input!=0; i *= 10){
		j = input%2;
		input = input/2;
		output = output + j*i;
		}
	printf("%llu", output);
		
	return 0;
 } 
