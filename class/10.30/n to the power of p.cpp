#include <stdio.h>


double power(double n, unsigned int p){
	if(p>0)
		return n*power(n, p-1);
	else
		return 1;	
}

int main()
{
	double i;
	unsigned int j;
	scanf("%lf %u", &i, &j);
	printf("%f", power(i, j));
}
