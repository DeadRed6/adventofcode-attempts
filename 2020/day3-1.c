#include <stdio.h>

//Each row is 31 characters wide.
//Take in each row at a time.
int main(void) {
	FILE *fp;
	fp = fopen("input-3", "r");
	
	char pattern[32]; //31 plus the null terminator
	int tree_count, row, column = 0;

	while(fscanf(fp, "%s", &pattern) != EOF) {		
		if(row != 0) {
			if(pattern[column % 31] == '#') tree_count++;
		}
		column += 3;
		row++;
	}
	
	printf("The number of trees is %d\n", tree_count);
	
	fclose(fp);
}
