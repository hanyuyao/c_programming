#include <stdio.h>

int main()
{	
	
	int i; 
	int in[10000];
	int flag;
	int k=0;
	int a, b, c, x;
	int del;
	
	int times;
	scanf("%d", &times);
	int flagg;
	for(flagg = 0; flagg < times; flagg++){
	
			
	                      
	scanf("%d", &i);       //how many numbers do you want to arrange. 
	for(flag = 0, k=0; flag < i; flag++){     //store the munbers in the array in[1000]
		scanf("%d", &in[k]);
		k++;
	}
	
						
	
	for(a=0, c=1; a<(i-1); a++, c++){     //Bubble Sort
		for(b=c; b<i;b++){
			if(in[a] > in[b]){
				x = in[a];
				in[a] = in[b];
				in[b] = x;
			}
		}
	}
	
	for(flag = 0; flag < i; flag++){
		printf("%d", in[flag]);
		
		if(flag==i-1)
			printf("\n");
		else
			printf(" ");
		}
		
				
	for(del = 0; del < i; del++)         //delete the array
			in[del]=0;
	
		
	}
	return 0;
}
