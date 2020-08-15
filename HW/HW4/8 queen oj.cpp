#include <stdio.h>

int valid(int row, int col);

void place(int row);


int q[8];
int board[64];
int max;

int main()
{
	int times;
	int k;
	int i;
		
	scanf("%d", &times);
	for(k = 0; k < times; k++){
		max=0;
		for(i = 0; i < 64; i++){
			scanf("%d",&board[i]);
		}
		
		place(0);
		printf("%d\n", max);
	}
	return 0;
 } 
 
 
 int valid(int row, int col)
 {
 	int i;
 	for(i = 0; i < row; i++){
 		if(col == q[i] || row-i == col-q[i] || row-i == q[i]-col)
 			return 0;
	}
	return 1;
 }
 
void place(int row)
 {
 	int i;
 	int count = 0;
   	if(row == 8){
		for(i = 0; i < 8; i++){
 			count += board[8*i+q[i]];
 		}
 		if(count > max){
 			max = count;
		}
 	}
	else{
		for(i = 0; i < 8; i++){
			if(valid(row, i)){
				q[row] = i;
				place(row + 1);
			}
		}
	}
}
 

