#include "function.h"

void execInst(int *ptrArr[], char inst, int param1, int param2){
    if(inst=='S'){
        *ptrArr[param1] = param2;
    }
    else if(inst=='M'){
        *ptrArr[param1] *= param2;
    }
    else if(inst=='P'){
        ptrArr[param1] = ptrArr[param2];
    }
}
int findMax(int *ptrArr[], int start, int end){
	int i, j;
	int temp;
	for(i = start, j = i+1; j <= end; j++){
		if(*ptrArr[i] < *ptrArr[j]){
			temp = *ptrArr[i];
			*ptrArr[i] = *ptrArr[j];
			*ptrArr[j] = temp;
		}	
	}    
    return *ptrArr[i];
}
