#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare_str(const void* a, const void* b)
{
	char**ca = (char**)a;
	char**cb = (char**)b;
	return strcmp(*ca, *cb);
}

int main()
{
	int n;
	int omaxlen, maxlen;
	int i, j;
	char* input;
	char** out;
	
	
	
	printf("How many strings do you want to compare?\n");
	scanf("%d", &n);
	printf("What's the max length of the strings?\n");
	scanf("%d", &omaxlen);
	printf("Enter %d strings\n", n);
	
	char* cmparr[n];
	
	maxlen = omaxlen+1;
	input = (char*)malloc(n*maxlen*sizeof(char));
	
	out = (char**)malloc(n*sizeof(char*));
	
	
	for(i = 0; i < n; i++){
		out[i] = &input[i*maxlen];
	}
	
	for(i = 0; i < n; i++){
		scanf("%s", out[i]);
		cmparr[i] = out[i];
	}	        

	qsort(cmparr, n, sizeof(char*), compare_str);
	
	for(i = 0; i < n; i++){
		printf("%s\n", cmparr[i]);
	}	
}
