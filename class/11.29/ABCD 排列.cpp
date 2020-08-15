#include <stdio.h>

void show(char *p);
void permutation(char *p);
void swap(char *p, char *q);


int main()
{
	char str[] = {'\0', 'A', 'B', 'C', 'D', '\0'};
	permutation(str);
	return 0;
}

void permutation(char *p)
{
	if(*p == '\0'){
		show(p-1);
		printf("\n");
	}
	else{
		char *q;
		q = p;
		while(*q != '\0'){
			swap(p, q);
			permutation(p+1);
			swap(p, q);
			q++;
		}
	}
}

void swap(char *p, char *q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void show(char *p)
{
	if(*p != 0){
		show(p-1);
		printf("%c", *p);
	}
}
