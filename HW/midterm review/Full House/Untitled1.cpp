#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	int flagg;
	scanf("%d", &n);
	for(flagg = 0; flagg < n; flagg++){
	
	
	char in[6];
	int flag;
	
	
	
	for(flag = 0; flag < 5; flag++){
		scanf("%s", &in[flag]);
		}
		
			
	int i, j;
	int count=0;
	for(i = 0; i < 4; i++){
		for(j = i+1; j<5; j++){
			if(in[i]==in[j])
				count += 1;
		}
	}
	
	if(count == 4)
		printf("YES\n")	;
	else
		printf("NO\n");
		
	
	}
	
	
		
	return 0;
	
 } 
