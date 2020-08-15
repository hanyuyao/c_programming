#include <stdio.h>

char map[1001][1001];
int m, n;
int i, j;
int status = 0;
void decide(int row, int col);

int main()
{
	scanf("%d %d", &m, &n);    //m rows, n cols
	for(i = 0; i < m; i++){
		scanf("%s", &map[i]);    //record the map
	}
	
	for(i = 0; i < m; i++){       //find the position of e
		for(j = 0; j < n; j++){
			if(map[i][j] == 'e'){
				decide(i, j);
			}
		}
	}
	
	if(status == 1){
		printf("Alive!\n");
	}
	if(status == 0){
		printf("Dead!\n");
	}	
	return 0;
} 

void decide(int row, int col)
{
	if(map[row][col] == '.' || map[row][col] == 'e'){
		map[row][col] = '^';
		decide(row+1, col);
		decide(row-1, col);
		decide(row, col+1);
		decide(row, col-1);
	}
	if(map[row][col] == '~'){
		status = 1;
	}		
}
