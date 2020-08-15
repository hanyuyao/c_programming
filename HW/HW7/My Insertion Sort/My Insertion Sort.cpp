#include <stdio.h>
#include <stdlib.h>
#include "11752.h" 

int compare(const void* a, const void* b)
{
    const int *va = (const int*)a;
    const int *vb = (const int*)b;
    return *va-*vb;
}


void assign(char* x, char* y, size_t size) {
	while(size > 0){
		*x = *y;
		x++;
		y++;
		size--;
	}
   // assign y to x
}

void mysort(void* arr, size_t count, size_t size, int (*cmp) (const void*, const void*))
{
	//a: array's starting memory address
	char* a = (char*)arr;
	int i, j;
	int x;
	for(i = 1; i < count; i++){
		x = a[i*size];
		for(j = i; j > 0 && compare(a+(j-1)*size, a+j*size)>0; j--){
			 assign(a+(j-1)*size, a+j*size);
		}
	}
	a[j*size] = x;
	
    // do sorting!!!
}       
//a[(j-1)*size] > a[j*size]
