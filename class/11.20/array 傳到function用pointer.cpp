#include <stdio.h>

void g(int* a, int n)   //int* a¥i¼g¦¨a[] 
{
	int i;
	for(i = 0; i < n; i++, a++)
		*a = i*1000;
		//*a = i*1000;
		
	// b[i] <----> *(b+i)
}

int main()
{
	int k;
	int x[10];
	g(x, 10);
	for(k = 0; k < 10; k++){
		printf("%d ",x[k]);
	}
	return 0;
}
