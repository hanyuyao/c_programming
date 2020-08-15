#include <stdio.h>
#include <string.h>

int main()
{
	char a[] = "Allen will be successful!";
	//char a[]   is the same as   char* a
	char b[] = "Allen will be successful!";
	char c[] = "Allen will exactly be successful!";
	int test_1 = strcmp(a, b);
	int test_2 = strcmp(a, c);
	
	printf("a and b are the same: %d\n", test_1);
	printf("a and c are not exactly the same: %d\n", test_2); 
} 
