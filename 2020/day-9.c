#include <stdio.h>

int main(void) {
	FILE *fp;
	fp = fopen("input-9", "r");
	
	long window[25]; //25 previous numbers, along with the new one.
	int index = 0;
	int i, j;
	long target; //On each iteration, we're trying to find two numbers that sum to this one.	
	short flag;
	
	while(fscanf(fp, "%lld", &target) != EOF) {		
		flag = 0;
		if(index > 24) {
			//At this point, we're done with the first 25. Time to get to work.
			
			for(i = 0; i < 24; i++) {
				for(j = i + 1; j < 25; j++) {
					if(target == window[i] + window[j]) {
						flag = 1;
						break;						
					}
				}
				if(flag == 1) break;
			}
			//If it does have a sum, then we graduate it to the holy heights of window			
			if(flag == 1) {
				window[index % 25] = target;
			} else {
				printf("%lld\n", target);
				break;
			}
		} else {
			window[index] = target;
		}
		index++;
	}
	
	fclose(fp);
}
