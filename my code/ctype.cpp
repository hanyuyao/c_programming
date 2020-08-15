#include <stdio.h>
#include <ctype.h>

int main()
{
	char ch;
	char a;
	while((ch = scanf("%c", &a)) != EOF){
	
		if(isspace(a))
			printf("is space\n");
		if(isdigit(a))
			printf("is digit\n");
		if(isalpha(a))
			printf("is alpha\n");
		if(isalnum(a))
			printf("is alnum\n");
		if(islower(a))
			printf("is lower\n");
		if(isupper(a))
			printf("is upper\n");
		if(isxdigit(a))
			printf("is x digit\n"); 
	}
}

