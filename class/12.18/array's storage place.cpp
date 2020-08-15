#include <stdio.h>

int main()
{
	int array[10];
	int i;
	for(i = 0; i < 10; i++){
		printf("%p\n", array+i);
	}
}
