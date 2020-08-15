#include <stdio.h>

int main()
{
	int len, times;
	scanf("%d", &len);
	scanf("%d", &times);
	
	int i, k;
	int flag;
	int ori[200001];
	int scan[100001];
	
	for(flag = 0; flag < len; flag++){
		ori[flag]=flag+1;
	}
	
	for(flag = times; flag > 0; flag--){
		scanf("%d", &scan[flag-1] );
	}
	
	
	for(k = 0; k < times; k++){
		for(i = 0; i < len; i++){
			if(ori[i]==scan[k]){
				printf("%d\n", scan[k]);
				ori[i]=0;
				break;
			}
		} 
	}
	
	for(i = 0; i < len; i++){
		if(ori[i] != 0){
			printf("%d\n", ori[i]);
		}
	}
	
	return 0;  
	
 } 
