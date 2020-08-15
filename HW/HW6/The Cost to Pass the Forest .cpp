#include <stdio.h>

int m, n;
char map[1000][1000];
int i, j;
void route(int, int);
void decide(int , int);
int count = 0;
int min = 100000;
int status = 0;

int main()
{
	scanf("%d %d", &m, &n);
	for(i = 0; i < m; i++){
		scanf("%s", &map[i]);
	}

	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			if(map[i][j] == 'S'){
				route(i, j);
			}
		}
	}
	
	if(status == 0)
		printf("0\n");
	else if(status == 1)
		printf("%d\n", min);
	return 0;
}

void route(int a, int b)
{
	decide(a+1, b);
	decide(a-1, b);
	decide(a, b+1);
	decide(a, b-1);
}

void decide(int a, int b)
{
	if(map[a][b] == '#'){
		count++;
		map[a][b] = 'S';
		
				
/*		for(i = 0; i < m; i++){
			for(j = 0; j < n; j++){
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
		printf("\n");    */
		    
		
		route(a, b);
		map[a][b] = '#';
		count--;
	}
	if(map[a][b] == 'T'){
		count++;
		min = (min < count)? min:count;
		
//		printf("count = %d min = %d\n", count, min);
		
		status = 1;
		count--;
	}
}
