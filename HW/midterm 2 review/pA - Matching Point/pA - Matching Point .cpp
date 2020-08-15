#include <stdio.h>
#include <string.h>

char arrays[21];
char arrayt[21];
int slen;
int tlen;
int count = 0;
void compare(int m, int n);

int main()
{
	while(scanf("%s %s", &arrays, &arrayt) != EOF){
		slen = strlen(arrays);
		tlen = strlen(arrayt);
		compare(0, 0);
		printf("%d\n", count);
		count = 0;
		memset(arrays, 0, 21*sizeof(arrays));
		memset(arrayt, 0, 21*sizeof(arrayt));
	}
}

void compare(int m, int n)
{
	if(m < slen && n < tlen){
		if(arrays[m] == arrayt[n]){
			compare(m+1, n+1);
			compare(m+1, n);
		}
		if(arrays[m] != arrayt[n]){
			compare(m+1, n);
		}
		if(arrays[m] == arrayt[n] && n == tlen-1){
			count++;
		}
	}
}
