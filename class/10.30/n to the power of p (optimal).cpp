#include <stdio.h>


double power(double n, unsigned int p){
// n^p = n^(p/2) * n^(p/2) * n if p is odd
//                         * 1 if p is even

	if(p>0){
		double ans = power(n, p/2);
		if(p%2)
			return n*ans*ans;
		else
			return ans*ans;
	}
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
