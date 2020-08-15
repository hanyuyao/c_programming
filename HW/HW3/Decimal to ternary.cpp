#include <stdio.h>

int main()
{
	int x, y;
	int f;
	int output[7];
	scanf("%d %d", &x, &y);
	for(f=1; f<=y; f++){
		output[y-f] = x%3;
		x = x/3;
		}
		
	for(f=1; f<=y; f++){
		printf("%d", output[f-1]);
		}
	printf("\n");
	
	
	return 0;
 } 
