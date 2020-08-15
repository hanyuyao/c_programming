#include <stdio.h>

float power(int a, int b){
	
	if(b == 0)
		return 1;
	else
		return a*power(a, b-1);	
}

float negative_power(int a, int b){
	return 1/power(a, -b);
}

int main()
{
	int a, b;
	
	
	printf("Enter two numbers for the base and the power:\n");
	while(scanf("%d %d", &a, &b) != EOF){
		if(b >= 0)
			printf("%f\n", power(a, b));
		if(b < 0)
			printf("%f\n", negative_power(a, b));
		printf("If you want to end this calculation, please hold ctrl and press z.\n");
		printf("If you want to continue, please enter another two numbers for base and power.\n");
	}
		
		
	
	return 0;
	
}
	

	

