#include <stdio.h>

int main()
{
    int i;                 //how many numbers do you want to read.
    scanf("%d", &i);
    int in[10000];          
    int flag;
    for(flag = 0; i > flag; flag++){     //store the numbers you want to read into the array "in"
        scanf("%d", &in[flag]);
        }
    int l;
    for(flag = 0; i > flag; flag++){      //print the numbers you stored.
        printf("%d ", in[flag]);
    }

}
