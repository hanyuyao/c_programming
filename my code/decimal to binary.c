#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rans[10000];
    int x;
    int i;
    int j;
    scanf("%d", &x);
    for(i = 0; x > 0; i++){
        rans[i] = x % 2;
        x /= 2;
    }

    for(j = i-1; j >= 0; j--){
        printf("%d", rans[j]);
    }

    printf("\n");

    return 0;
}
