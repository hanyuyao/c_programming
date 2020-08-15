#ifndef FUNCTION_H
#define FUNCTION_H

void flooding(int pr, int pc);
char Map[505][505];

#endif

#include <stdio.h>
//#include "function.h"

int main(void){
    int N,R,C,X,Y,i,j,k;
    scanf("%d", &N);
    for(k=0;k<N;k++){
        scanf("%d%d%d%d", &R, &C, &Y, &X);

            for(i=0;i<R;i++){
                for(j=0;j<C;j++){
                    Map[i][j] = ' ';
                }
            }
            for(i=0;i<R;i++){
                scanf("%s", Map[i]);
            }

            flooding(Y,X);
            for(i=0;i<R;i++){
                for(j=0;j<C;j++){
                    printf("%c", Map[i][j]);
                }
                printf("\n", Map[i][j]);
            }
            if(k<N-1)
                printf("\n", Map[i][j]);
    }
    return 0;
}

void flooding(int pr, int pc)
{
	Map[pr][pc] = 'W';
	if(Map[pr+1][pc] == 'H')
		flooding(pr+1, pc);
	if(Map[pr-1][pc] == 'H')
		flooding(pr-1, pc);
	if(Map[pr][pc+1] == 'H')
		flooding(pr, pc+1);
	if(Map[pr][pc-1] == 'H')
		flooding(pr, pc-1);
	
}

