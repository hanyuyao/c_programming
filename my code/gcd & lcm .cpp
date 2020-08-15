#include <stdio.h>

int gcd(int a, int b)
{
	if(a%b != 0)
		gcd(b, a%b);
	else
		return b; 
}

main()
{
	int i, j;
	while(scanf("%d %d", &i, &j) != EOF){
		printf("The greatest common divisor is %d.\n", gcd(i, j));
		printf("The least common multiple is %d.\n", i*j/gcd(i, j));
	}
} 
