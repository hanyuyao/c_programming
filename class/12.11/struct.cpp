#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LONGSTR "asdfkjlkxcjvlkjivxzvzxmvksdjvlkadjjfaskdfisjdvkxcvxvksjdlkfj" 

int i;
typedef struct{
	int x;
	double y;
	char z[80];
}Somestruct;

void setup(Somestruct *p, int sz)
{
	for(i = 0; i < sz; i++){
		p[i].x = i;
		p[i].y = i/3.0;
		strncpy(p[i].z, LONGSTR, i);
	}
}

void show(Somestruct *p, int sz)
{
	for(i = 0; i < sz; i++){
		printf("%d %f %s\n", p[i].x, p[i].y, p[i].z);         
		}
}

int main()
{
	Somestruct *a;
	
	a = (Somestruct*) malloc(50*sizeof(Somestruct));
	setup(a, 50);
	show(a, 10);
}
