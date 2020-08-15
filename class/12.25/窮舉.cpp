#include <stdio.h>
int main(void)
{
    int N, i, j, lim;
    int num[16];
	printf("How many numbers do you want to Ωa¡|?\n");
    scanf("%d", &N);
    printf("Enter %d numbers:\n", N);
    for (i=0; i<N; i++) {
        scanf("%d", &num[i]);
    }

    lim = 1<<N;

    for (i=0; i<lim; i++) {
        for (j=0; j<N; j++)  {
            if ( (i & (1<<j))!= 0 ) {
                printf("%d ", num[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
