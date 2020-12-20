#include <stdio.h>

//Each row is 31 characters wide.
//Take in each row at a time.
int main(void) {
	printf("Result is: %lld\n", tree_counter(1,1) * tree_counter(3,1) * tree_counter(5,1) * tree_counter(7,1) * tree_counter(1,2));
}

int tree_counter(int x, int y) {
	FILE *fp;
	fp = fopen("input-3", "r");
	
	char pattern[32]; //31 plus the null terminator
	int tree_count = 0;
	int row = 0;
	int column = 0;
	
	while(fscanf(fp, "%s\n", &pattern) != EOF && row < 323) {		
		if(row != 0) {
			if(row % y == 0) {
				column += x; //Advance the slope by delta x
				if(pattern[column % 31] == '#') tree_count++;
			}
		}
		row++; //Move down to the next row
	}

	return tree_count;
			
	fclose(fp);
}
