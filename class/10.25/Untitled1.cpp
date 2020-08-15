#include <stdio.h>
#include <ctype.h>

int main()
{
	int ch;
	int sum = 0;
	while ((ch=getchar()) != EOF){
		putchar(ch);
		if (isdigit(ch)){
			sum = sum*10 + ch-'0';
			}
	}
	printf("%d\n", sum);
	
	return 0;
 } 
 
 
 
 
 //isdigit(ch)
 //tolower(ch)
 //toupper(ch)
   
 
 //EOF in window is : ctrl z 
 
