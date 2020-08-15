#include <stdio.h>

int main()
{
	int a[10];
	a[5] = 33;
	printf("%d\n", *(a+5));
	printf("%d\n", &a[5]);
	printf("%d\n", &5[a]);
	printf("%d\n", (a+5));
}

// a[i]  <--->  *(a+i)
// &a[i] <--->  (a+i)
