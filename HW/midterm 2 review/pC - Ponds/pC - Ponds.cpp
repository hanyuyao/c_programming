#include <stdio.h>

int count = 0;
int m, n;
void pond(int row, int col);
void turn(int i, int j);
char map[1001][1001];
 
int main()
{
	int i, j;
	scanf("%d %d", &m, &n);    //m rows, n columes
	
	for(i = 0; i < m; i++){
		scanf("%s", &map[i]);
	}
	
	pond(m, n);
	printf("%d\n", count);
}

void pond(int row, int col)
{
	int i, j;
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			if(map[i][j] == '~'){
				count++;
				turn(i, j);
			}
		}
	}
}

void turn(int i, int j)
{
	map[i][j] = '.';
	if(map[i+1][j] == '~'){
		map[i+1][j] = '.';
		turn(i+1, j);
	}
	if(map[i-1][j] == '~'){
		map[i-1][j] = '.';
		turn(i-1, j);
	}
	if(map[i][j+1] == '~'){
		map[i][j+1] = '.';
		turn(i, j+1);
	}
	if(map[i][j-1] == '~'){
		map[i][j-1] = '.';
		turn(i, j-1);
	}
}
