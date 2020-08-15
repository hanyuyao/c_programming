#include <stdio.h>

int main()
{
	unsigned long long input;
	int output[65];
	int i, j;
	scanf("%llu", &input);
	for(j=0; input!=0; j++){
		i = input%2;
		output[j]= i;
		input /= 2;
	}
	
	for(j -= 1; j>=0; j--){
		printf("%d", output[j]);
	
	}
	
	printf("\n");
	return 0;
}
