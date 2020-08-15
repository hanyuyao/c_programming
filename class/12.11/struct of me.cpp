#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
	char z[10];
}allen;

void set_struct(allen *a, int height, int weight, char des[10])
{
	a->x = height;
	a->y = weight;
	strcpy(a->z, des);
}

int main()
{
	allen me;
	set_struct(&me, 176, 64, "tender, warm and mature.");
	printf("My height is %d\n", me.x);
	printf("My weight is %d\n", me.y);
	printf("My personality is %s\n", me.z);
	
}
