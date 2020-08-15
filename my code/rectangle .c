#include <stdio.h>
#define ABC "*****************************************"

int main()
{
	int i, j;
	int k;
	int c;
	printf("Please enter the width of the rectangle you want:\n");
	scanf("%d", &i);
	printf("Please enter the length of the rectangle you want:\n");
	scanf("%d", &j);
	printf("The rectangle you assign looks like this:\n");
	for(k=0; k<i; k++)
		printf("%.*s\n", j, ABC);
	printf("Enter anything to exit.");
	scanf("%d", &c);
	printf("Bye~");
	
	return 0;
}
