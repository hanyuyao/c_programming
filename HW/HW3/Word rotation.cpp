#include <stdio.h>
#include <string.h>
int main()
{
	char input[1000];
	scanf("%s", &input);
	int len;
	len = strlen(input);
	int index, windex;
	char first[1];
	
	for(windex=0; windex<len; windex++){
		first[0] = input[0];
		for(index=0; index<(len-1); index++){
			input[index] = input[index + 1];
			}
		input[len-1] = first[0];
		printf("%s\n", input);
	}
	return 0;
 } 
