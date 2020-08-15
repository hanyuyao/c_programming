#include <stdio.h>


int gcd(int i, int j){
		if(j == 0)
			return i;
		else
			return gcd(j, i%j);
	}
	
	
int main()
{
	int times;
	int n;
	int flagg;
	int pony[100002]={0};
	int x[4];
	int gcdd[4];
	int flag, i;
	int ans=0;
	
	scanf("%d", &times);
	for(flagg = 0; flagg < times; flagg++){
		scanf("%d", &n);
		
		
	for(flag = 1; flag < 4; flag++){
		scanf("%d", &x[flag]);
	}
	
		
	
	gcdd[1]=gcd(n, x[1]);
	gcdd[2]=gcd(n, x[2]);
	gcdd[3]=gcd(n, x[3]);
	
	if(n%x[1] == 0){
		for(i = x[1], flag = 1; flag <= n/gcdd[1]; i += x[1], flag++){
			pony[i] += 1;
		}
	}
	else{
		for(i = gcdd[1], flag = 1; flag <= n/gcdd[1]; i += gcdd[1], flag++){
			pony[i] += 1;
		}
	}
	
	
	if(n%x[2] == 0){
		for(i = x[2], flag = 1; flag <= n/gcdd[2]; i += x[2], flag++){
			pony[i] += 1;
		}
	}
	else{
		for(i = gcdd[2], flag = 1; flag <= n/gcdd[2]; i += gcdd[2], flag++){
			pony[i] += 1;
		}
	}
	
	
	if(n%x[3] == 0){
		for(i = x[3], flag = 1; flag <= n/gcdd[3]; i += x[3], flag++){
			pony[i] += 1;
		}
	}
	else{
		for(i = gcdd[3], flag = 1; flag <= n/gcdd[3]; i += gcdd[3], flag++){
			pony[i] += 1;
		}
	}
	
	for(flag = 1; flag < n+1; flag++){
		if(pony[flag] == 3){
			ans += 1;
		}
	}
	
	printf("%d\n", ans);
	
	}
	
	return 0;
}
