#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{	
	char *str = "programming";
	//字元指標類型的字串可以有初始值 
	char a[] = "programming";
	printf("str: %s\n", str);
	printf("a: %s\n", a);
	
	int i;
	for(i = 0; i < strlen(str); i++){
		printf("%c", str[i]);
	}
	printf("\n\n");
	
	
	printf("Enter a string:\n");
	char *charptr;
	char array[80];
	charptr = array;
	scanf("%s", array);
	printf("%s", charptr);
}

