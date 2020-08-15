#include <stdio.h>

int main()
{
	double x;
	int interger;
	double fraction;
	int ransi[10000];
	int i, j;
	
	int ansf[10000];
	
	scanf("%lf", &x);
	
	if(x < 0){
		printf("-");
		x = -x;
	}
		
	interger = x/1;
	fraction = x - interger;
	
	
			
	if(interger == 0){
		printf("%d", 0);
	}
	
	for(i = 0; interger > 0; i++){
		ransi[i] = interger%2;
		interger /= 2;
	}
	
	for(j = i-1; j >= 0; j--){
		printf("%d", ransi[j]);
	}
	
	printf(".");
	
	for(i = 0; i < 10; i++){
		fraction *= 2;
		
		if(fraction > 1){
			ansf[i] = 1;
			fraction -= 1;
		}
		
		else if(fraction < 1){
			ansf[i] = 0;
		}
		
		else{
			ansf[i] = 1;
			break;
		}
	}
	
	for(j = 0; j < 10; j++){
		printf("%d", ansf[j]);
	} 
	
	printf("\n");
	return 0;
 } 
