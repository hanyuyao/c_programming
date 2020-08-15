#include <stdio.h>

int F(int i)
{
	if(i > 0){
		if(i >= 3)
			return F(i-1) + F(i-2);
		if(i == 2)
			return 2;
		if(i == 1)
			return 1;
	}
}

int main()
{
	int times;
	int flag;
	int i;
	
	scanf("%d", &times);
	
	for(flag = 0; flag < times; flag++){
		scanf("%d", &i);
		printf("%d\n", F(i));
	}
}
