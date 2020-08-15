#include <stdio.h>

int count = 0;

int q[11] = {0};

void place(int row, int N);
int valid(int row, int col);


int main(void)
{
	int N;
	scanf("%d", &N);
	place(0, N);
	printf("%d", count);
	return 0;
}


int valid(int row, int col)
{
	int i;
	for (i=0; i<row; i++) {
		if ( q[i] == col || row-i == col-q[i] || row-i == q[i]-col )
		return 0;
	}
	return 1;
}



void place(int row, int N)
{
	int j;
	if (row == N) {
		count++;
	} else {
		for (j=0; j<N; j++) {
			if (valid(row, j)) {
				q[row] = j;
				place(row+1, N);
			}
		}
	}
}
