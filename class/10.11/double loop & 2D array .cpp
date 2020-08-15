#include <stdio.h>
#define SIZE 10

int main()
{
	int a[SIZE][SIZE];
	int num;
	int i, j;
	
	i = 0;
 	while(i<SIZE){
 		j = 0;
 		while(j<SIZE){
 			a[i][j] = i*j;
 			j++;
		 }
 		++i;
	 }
	 
	 i = 0;
 	while(i<SIZE){
 		j = 0;
 		while(j<SIZE){
 			printf("%3d", a[i][j]);
 			j++;
		 }
		 printf("\n");
 		++i;
	 }
	
	
	
	
	return 0;
	
 } 
