// A piece of C code
#include <stdio.h>
#define MAXNV 5
int values[MAXNV];
int numbers[MAXNV];

void show(int nv);
void change(int amount, int smallest, int nv);

int main(void)
{
	int nv, i;
	int money;

	scanf("%d", &nv);
	if (nv>MAXNV || nv<1) return 0;

	for (i=0; i<nv; i++) {
		scanf("%d", &values[i]);
	}

	scanf("%d", &money);
	change(money, 0, nv);

	return 0;
}

void show(int nv)
{
	int i;
	printf("(%d", numbers[0]);
	for (i=1; i<nv; i++) {
		printf(",%d", numbers[i]);
	}
	printf(")\n");
}



void change(int amount, int smallest, int nv)  //smallest眖1秨﹍ 
{
	if (smallest<nv) {
		if (amount == 0) {
			show(nv);
		} else if (amount > 0) {
			change(amount, smallest+1, nv);  //场ノ10じ传 
			numbers[smallest]++;
			change(amount-values[smallest], smallest, nv); //ノ10じ临传碭 
			numbers[smallest]--; //р10じΙ奔1Ω跑Θノ5じ传 
		}
	}
}


//amount:羆窥计 smallest:程窥⒈⒉だ⒋⒋じ

