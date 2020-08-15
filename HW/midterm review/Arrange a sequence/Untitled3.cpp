#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int in[200001];
	int flag;
	int i, j;
	int ch;
	int check[200001];
	int count=0;
	
	for(flag = 0; flag < n; flag++){
		in[flag]=flag+1;
	}
	
	for(j=0; j<m; j++){
		scanf("%d", &ch);
		check[j]=ch;
		for(flag = 0; flag <j; flag++){
			if(check[flag]>ch){
				count++;
			}
		}
		
		for(i=1; (ch-i+count)>0; i++){
			in[ch-i+count]=in[ch-(i+1)+count];
		}
		in[0]=ch;
		
		}
	
	for(flag = 0; flag < n; flag++){
		printf("%d\n", in[flag]);
	}
}
