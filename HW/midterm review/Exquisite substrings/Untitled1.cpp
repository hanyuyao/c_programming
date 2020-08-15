#include <stdio.h>
#include <string.h>

int main()
{
	char in[2001];
	char in2[2001];
	int n;
	char ch;
	int i;
	while((ch = getchar()) != EOF){
		for(i = 0; ch != EOF && ch != '\n'; ch = getchar(),i++)
			in[i] = ch;
		
	
		
	}
	
	printf("%s\n", in);
	printf("%s", in2);
	return 0;
}
