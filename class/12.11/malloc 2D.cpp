#include <stdio.h>
#include <stdlib.h>

int main()
{
   int *a;
   int **b;
   int i, j;
   int rows, cols;
   
   scanf("%d %d", &rows, &cols);
   a = (int*) malloc(rows * cols * sizeof(int));
   //a as a 1D array, size: rows*cols;
   for (i = 0; i < rows*cols; i++) a[i] = i;
   
   b = (int**)malloc(rows * sizeof(int*));
   //b as a 1D pointer array, size: rows;

   for (i = 0 ; i < rows; i++) 
   		b[i] = &a[i*cols];
   	//b[i]'s data type : int*
   	//array b store a's every start memory address

   for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
         printf("%3d ", b[i][j]); 
      }
      printf("\n");
   }
   
   free(b);
   free(a);

   return 0;
}


