#include <stdio.h>

void f(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int x, y;
	printf("Enter two interger for exchange:\n");
	scanf("%d %d", &x, &y);

	printf("%d %d\n", x, y);
	f(&x, &y);
	printf("%d %d", x, y);
	
	return 0;
}
