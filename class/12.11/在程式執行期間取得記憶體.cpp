#include <stdio.h>
#include <stdlib.h>
int main(void)
{
   double *ptd;
   int array_size, i;
   
   int count = 0;

   printf("How many doubles do you want? ");
   scanf("%d", &array_size);
   ptd = (double *) malloc(array_size * sizeof (double));
   if (ptd == NULL) {
      printf("Memory allocation failed.\n");
      exit(EXIT_FAILURE);
   }

   for (i = 0; i < array_size; i++) {
      ptd[i] = (double) rand() / RAND_MAX;
   }          //把0到1之間的數放到ptd裡面 
   
   for (i = 0; i < array_size; i++) {
      if (*(ptd+i) > 0.5){
        printf("%d: %f\n", i, ptd[i]);
		count++; 
		}
   }

   free(ptd);
   
   printf("%d", count);

   return 0;
}
