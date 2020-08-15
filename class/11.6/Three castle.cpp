#include <stdio.h>



int board[5][5];

void place(int row);

void show_board(void)

{

	int i, j;

	for (i=1; i<=3; i++) {

		for (j=1; j<=3; j++) {

			printf(" %d", board[i][j]);

		}

		printf("\n");

	}

	printf("\n");

}

int main(void)

{

	place(1);

	return 0;

}

int valid(int row, int col)

{

    int i;

    for (i=1; i<row; i++) {

        if (board[i][col]) return 0;

    }

    return 1;

}

void place(int row)

{

	int i;

	if (row>3) {

		show_board();

	} else {

		for (i=1; i<=3; i++) {

		    if (valid(row, i)) {

			    board[row][i] = 1;

			    place(row+1);

			    board[row][i] = 0;

			}

		}

	}

}
