#include <stdio.h>
#include <string.h>

int main()
{
	char a[5];
	char b[10];
	int n;
	int flag, flagg;
	int ans[10]={0};
	int i, j;
	int out;

	
	scanf("%s", &a);
	scanf("%d", &n);
	
	
	for(flag = 0; flag < n; flag++){
		scanf("%s", &b);
		if(strlen(a) == 1){
			for(flagg = 0; flagg < strlen(b); flagg++){
				if(a[0]==b[flagg])
					ans[flag] += 1;
			}
		}
		
		if(strlen(a) == 2){
			for(flagg = 0; flagg < strlen(b)-1; flagg++){
				if((a[0]==b[flagg]) && (a[1]==b[flagg+1]))
					ans[flag] += 1;
			}
		}
		
		if(strlen(a) == 3){
			for(flagg = 0; flagg < strlen(b)-2; flagg++){
				if((a[0]==b[flagg]) && (a[1]==b[flagg+1]) && (a[2]==b[flagg+2]))
					ans[flag] += 1;
			}
		}
		
		if(strlen(a) == 4){
			for(flagg = 0; flagg < strlen(b)-3; flagg++){
				if((a[0]==b[flagg]) && (a[1]==b[flagg+1]) && (a[2]==b[flagg+2])&&(a[3]==b[flagg+3]))
					ans[flag] += 1;
			}
		}
		
	}
	

	
	out = ans[0];	
	for(flag = 0; flag < n; flag++){
		if(out<ans[flag])
			out = ans[flag];
		}
		
	printf("%d", out);
	return 0;
	
 } 
