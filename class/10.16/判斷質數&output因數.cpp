#include <stdio.h>

int main()
{
	int num, a=0;
	int i;
	printf("Enter a integer:\n");
	scanf("%d", &num);
	
	for(i=2; num>i; ++i){
		if(num % i == 0){
			a = 1;
			printf("%d ", i);
		}
	}
	
	if(a==0)
		printf("The number is a prime.");
	
	return 0;
}
