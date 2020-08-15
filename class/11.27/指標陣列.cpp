#include <stdio.h>

void g(int a[][4]);
 
int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int* bp[3];
	int i, j;
	
	for(i = 0; i < 3; i++)
		bp[i] = &a[i*4];            //bp[i]是記憶體位置 
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 4; j++){
			printf("%3d", bp[i][j]);
			// bp[i] [j] ===> *(bp[i]+j)
			//           ===> *( &a[i*4] + j)
			//           ===> *( &*(a + i*4) + j)
			//           ===> *( a + i*4 + j)
			//           ===> a[i*4 + j]
		}
		printf("\n");
	}
 }  
