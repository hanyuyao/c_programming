#include <stdio.h>

void hanoi(char start, char end, char buf, int N)
{
	if(N > 0){
		hanoi(start, buf, end, N-1);
		printf("pole %c -> pole %c\n", start, end);
		hanoi(buf, end, start, N-1);
	}
}


int main()
{
	int x;
	scanf("%d", &x);
	hanoi('1', '3', '2', x);
	return 0;
}
