#include <stdio.h>


void bin(int i){
    if( i != 1 ) bin(i/2);
  	printf("%d",i%2 );
}

int main(void){
    int n;
    scanf("%d", &n);
    bin(n);
    return 0;
}
