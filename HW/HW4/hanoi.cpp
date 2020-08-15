#include <stdio.h>
//#include "function.h"
void hanoi(int n, char A, char B, char C)
{
	if(n > 0){
 	    hanoi(n - 1, A, C, B);
 	    printf("%d\n", n);
  		hanoi(n - 1, B, A, C);
	}
}

int main()
{
	int i;
	scanf("%d", &i);
	hanoi(i, '1', '2', '3');
}
