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
	return 0;
}

void compare(int m, int n)
{
	int i;
	if(n == tlen){
		count++;
	}
	else{
		for(i = m; i < slen; i++){
			if(arrays[i] == arrayt[n]){
				compare(i+1, n+1);
			}
		}
	}
}
