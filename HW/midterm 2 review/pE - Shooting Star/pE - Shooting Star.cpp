#include <stdio.h>

char map[100][100];
int c, f, h, s;
int i, j;
char direction;
void initial(void);
void reflect(int a, int b, char dir);
void show_map(void);
//char u, d;
int count_wide = 1;

int main()
{
//	freopen("123.txt", "w", stdout);
	scanf("%d %d %d %d %c", &c, &f, &h, &s, &direction);
	initial();                           
	
	map[s][0] = '*';
	reflect(s, 0, direction);
	show_map();
	
}

void initial(void)
{
	for(i = 0; i < 50; i++){
		for(j = 0; j < 50; j++){
			map[i][j] = ' ';
		}
	}
	for(i = 0; i < c; i++){
		map[0][i] = '-';
	} 
	for(j = 0; j < f; j++){
		map[h+1][j] = '-'; 
	}
}

void reflect(int a, int b, char dir)
{
	if(a > 0 && a < h+1){
		if(dir == 'u'){
			if(map[a-1][b] != '-'){
				map[a-1][b+1] = '*';
				count_wide++;
				reflect(a-1, b+1, 'u');
			}
			if(map[a-1][b] == '-'){
				reflect(a, b, 'd');
			}
		}
		
		if(dir == 'd'){
			if(map[a+1][b] != '-'){
				map[a+1][b+1] = '*';
				count_wide++;
				reflect(a+1, b+1, 'd');
			}
			if(map[a+1][b] == '-'){
				reflect(a, b, 'u');
			}
		}
	}
}

void show_map(void)
{
	int temp_wide, wide;
	temp_wide = (c > f)? c:f;
	wide = (temp_wide > count_wide)? temp_wide:count_wide;
	
	for(i = 0; i < h+2; i++){
		for(j = 0; j < wide; j++){
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}


