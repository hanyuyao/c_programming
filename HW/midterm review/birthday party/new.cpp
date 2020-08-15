#include <stdio.h>

int gcd(int a, int b){
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}

int lcm(int a, int b){
	return (a*b)/gcd(a,b);
}

int main()
{
	int n;
	int pony[100002];
	int x[4];
	int gcdd[4];
	int flag;
	int lcmm;
	int ans;
	int times, flagg;
	
	
	scanf("%d", &times);
	for(flagg = 0; flagg < times; flagg++){
		
	scanf("%d", &n);
	for(flag = 1; flag < 4; flag++){
		scanf("%d", &x[flag]);
	}
	
	
	for(flag = 1; flag < 4; flag++){
		gcdd[flag] = gcd(n, x[flag]);
	}
	
	lcmm = lcm(lcm(gcdd[1], gcdd[2]), gcdd[3]);
	
	ans = n/lcmm;
	printf("%d\n", ans);
	}
	
	
 } 
