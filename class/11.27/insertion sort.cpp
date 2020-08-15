#include <stdio.h>

void mysort(int a[], int n)     //將資料由小排到大 
{
	int i, j;
	int x;
	for(i = 0; i < n; i++){
		x = a[i];
		j = i;
		while(j > 0 && a[j-i] > x){
			a[j] = a[j-i];
			j--;
		}
	}
}
int main()
{
	
}
