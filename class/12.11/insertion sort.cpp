#include <stdio.h>

void insertion_sort(int a[], int n){
	int i, j, k;
	int x;
	for(i = 1; i < n; i++){
		x = a[i];
		for(j = i; j > 0 && a[j-1] > x; j--){
			a[j] = a[j-1];
		}
		a[j] = x;
			
			
		for(k = 0; k < 10; k++){
			printf("%d ", a[k]);
		}
		printf("\n");
	}
}


int main()
{
	printf("Enter 10 intergers:\n");
	
	int i;
	int array[10];
	for(i = 0; i < 10; i++){
		scanf("%d", &array[i]);
	}
	insertion_sort(array, 10);
	for(i = 0; i < 10; i++){
		printf("%d ", array[i]);
	}
}
