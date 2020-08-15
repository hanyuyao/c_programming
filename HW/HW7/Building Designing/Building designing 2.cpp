#include <stdlib.h>
#include "function.h"
#define RED 0
#define BLUE 1
int compare(const void *a, const void *b) {
	const Floor* fa = (const Floor*)a;
	const Floor* fb = (const Floor*)b;
	return fb->size - fa->size;
//  Your  code
}
// Modify the design function
int design(int floorNum, Floor floorArr[]) {
    int height, color, eo;
    int idx;
    qsort(floorArr, floorNum, sizeof(Floor), compare);
    height = 1;
    eo = (floorArr[0].size%2 == 1)? 1:0;
    color = (floorArr[0].color == 'B') ? BLUE : RED;
    for (idx = 1; idx < floorNum; idx++) {
        if (color == BLUE && floorArr[idx].color == 'R') {
        	if(eo == 1 && floorArr[idx].size%2 == 0){
        		height++;
            	color = RED;
            	eo = 0;
			}
			else if(eo == 0 && floorArr[idx].size%2 == 1){
        		height++;
            	color = RED;
            	eo = 1;
			}
        }
        else if (color == RED && floorArr[idx].color == 'B') {
        	if(eo == 1 && floorArr[idx].size%2 == 0){
        		height++;
            	color = BLUE;
            	eo = 0;
			}
			else if(eo == 0 && floorArr[idx].size%2 == 1){
        		height++;
            	color = BLUE;
            	eo = 1;
			}
        }
    }
    return height;
}
