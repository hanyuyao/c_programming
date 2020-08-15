#include <stdio.h>


int main()
{
	int n, i, j;			//total points equals to n.
	int k, l;
	int point[1000][2];
	int x[200002];				//x coordinate
	int y[200002];				//y coordinate
	int ans = 0;
	int slope[10000];
	
	int count = 0;
	int countt = 0;
	int times;
	int flag;
	
	scanf("%d", &times);
	
	for(flag = 0; flag < times; flag++){
		
	scanf("%d", &n);
	for(i=0; i<n; i++){
		for(j=0; j<2; j++)
			scanf("%d", &point[i][j]);
	}
		
	for(k=1, i=0; i<n; i++, k++){        //第一個點的X座標為x[1] 
		x[k]=point[i][0];
	}
	
	for(l=1, i=0; i<n; i++, l++){		//第一個點的Y座標為y[1] 
		y[l]=point[i][1];
	}
	
	for(i=1; i<n-1; i++){
		for(j=i+1; j<n; j++){
			for(k=j+1; k<n+1; k++){
				if(((y[i]-y[j]) != 0) && ((y[i]-y[k]) != 0)){
					if(for(flag = slope; flag > 0 ;flag--){
						((x[i]-x[j])/(y[i]-y[j])) != slope[slope];
					})
					{
						
						if(((x[i]-x[j])/(y[i]-y[j])) == ((x[i]-x[k])/(y[i]-y[k]))){
							count += 1;
							}
							if(count >= 1){
								ans += 1;
								slope[ans] = (x[i]-x[j])/(y[i]-y[j]);
							}
						}
					
				}
			}
				
				if(((y[i]-y[j]) == 0) && ((y[i]-y[k]) == 0)){
					if(for(flag = slope; flag > 0 ;flag--){
						((x[i]-x[j])/(y[i]-y[j])) != slope[slope];
					})
					countt += 1;
				}
				if(count >= 1){
					ans += 1;
					slope[ans] = (x[i]-x[j])/(y[i]-y[j]);
				}
				
				
		}
	}
	
		
	printf("%d\n", ans);
	}

	return 0;
 } 
