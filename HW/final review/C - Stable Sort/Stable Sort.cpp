#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char name[21];
	int score;
	int number;
}Student;

compare(const void* a, const void* b)
{
	Student* sa = (Student*)a;
	Student* sb = (Student*)b;
	if(sa->score != sb->score) return sb->score - sa->score;
	else return sa->number - sb->number;
}


int main()
{
	freopen("123.txt", "r", stdin);
	int n;
	int i, j;
	scanf("%d", &n);
	Student* record = (Student*)malloc(n*sizeof(Student));
	for(i = 0; i < n; i++){
		scanf("%s %d", &record[i].name, &record[i].score);
		record[i].number = i;
	}
	
	qsort(record, n, sizeof(Student), compare);
	
	for(i = 0; i < n; i++){
		printf("%s\n", record[i].name);
	}
	return 0;
} 
