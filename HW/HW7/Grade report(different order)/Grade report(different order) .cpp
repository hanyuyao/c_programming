#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "10895.h"

int compare_a(const void* a, const void* b)
{
	const Grade* ca = (const Grade*)a;
	const Grade* cb = (const Grade*)b;
	if(ca->total != cb->total) return ca->total - cb->total;
	else if(ca->Chinese != cb->Chinese) return ca->Chinese - cb->Chinese;
	else if(ca->English != cb->English) return ca->English - cb->English;
	else if(ca->math != cb->math) return ca->math - cb->math;
	else if(ca->science != cb->science) return ca->science - cb->science;
	else return ca->ID - cb->ID;
}

int compare_d(const void* a, const void* b)
{
	const Grade* ca = (const Grade*)a;
	const Grade* cb = (const Grade*)b;
	if(ca->total != cb->total) return cb->total - ca->total;
	else if(ca->Chinese != cb->Chinese) return cb->Chinese - ca->Chinese;
	else if(ca->English != cb->English) return cb->English - ca->English;
	else if(ca->math != cb->math) return cb->math - ca->math;
	else if(ca->science != cb->science) return cb->science - ca->science;
	else return ca->ID - cb->ID;
}

void sortGrade(Grade *gList, int n, char *order)
{
	int i;
	for(i = 0; i < n; i++){
		gList[i].total = gList[i].Chinese+gList[i].English+gList[i].math+gList[i].science;
	}
	if(order[0] == 'a'){
		qsort(gList, n, sizeof(Grade), compare_a);
	}
	if(order[0] == 'd'){
		qsort(gList, n, sizeof(Grade), compare_d);
	}
}


