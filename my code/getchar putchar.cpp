#include <stdio.h>

int main()
{
	char in[10000];
	int flag;
	for(flag = 0; (in[flag] = getchar()) != EOF;flag++){
		putchar(in[flag]);
	}
	
	return 0;
}
