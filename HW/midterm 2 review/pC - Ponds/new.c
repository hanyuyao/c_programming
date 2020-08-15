#include <stdio.h>

int m, n;
int i, j;
int count = 0;
char map[1001][1001];

void turn(int, int);

int main()
{
    scanf("%d %d", &m, &n);
    for(i = 0; i < m; i++){
        scanf("%s", &map[i]);
    }

    for(i = 0;i < m; i++){
        for(j = 0; j < n; j++){
            if(map[i][j] == '~'){
                count++;
                turn(i, j);
            }
        }
    }

    printf("%d\n", count);
    return 0;
}

void turn(int a, int b)
{
    if(map[a][b] == '~'){
        map[a][b] = '.';
        turn(a+1, b);
        turn(a-1, b);
        turn(a, b+1);
        turn(a, b-1);
    }
}
