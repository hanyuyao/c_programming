#include <stdio.h>
#include <string.h>
#include <ctype.h>
//�Ψ�ƩM���j�Ӽg n!

int n_stage(int a){
	
	if (a==1) return 1;
	return a*n_stage(a-1);
}
int main()
{
	int i;
	scanf("%d", &i);
	printf("%d", n_stage(i));
}
