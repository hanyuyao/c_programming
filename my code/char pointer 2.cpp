#include <stdio.h>

int main(void)
{
    char *str1[] = {"piece", "of", "cake"};
    char str2[][8] = {"piece", "of", "cake"};
    int i, j;
    
    for(i = 0; i < 3; i++){
    	printf("%s\n", str1[i]);
	}
	printf("\n");
	
	printf("%s\n", str1[0]);
	printf("\n");
 
    for (i=0; i<3; i++) {
        for (j=0; j<8; j++)
            printf("%c", str2[i][j]);
        printf("\n");
    }           
    return 0; 
}
