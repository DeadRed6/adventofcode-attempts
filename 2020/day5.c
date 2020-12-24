#include <stdio.h>

int main(void) {
	FILE *fp;
	fp = fopen("input-5", "r");
	
	char seat[10];
	short row_lower;
	short row_upper;
	short row_value; //The middle of the two
	short column_lower;
	short column_upper;
	short column_value;	
	
	int seat_id = 0;
	
	while(fscanf(fp, "%s\n", &seat) != EOF) {
		row_lower = 0;
		row_upper = 127;
		row_value = 63;		
		column_lower = 0;
		column_upper = 7;
		column_value = 3;
		int i;
		for(i = 0; i < 10; i++) {
			if(i < 7) {
				if(seat[i] == 'F') {
					row_upper = row_value;
				} else {
					row_lower = row_value + 1;
				}
				row_value = (row_lower + row_upper) / 2;
			} else {
				if(seat[i] == 'L') {
					column_upper = column_value;
				} else {
					column_lower = column_value + 1;
				}
				column_value = (column_lower + column_upper) / 2;	
			}
		}
		int temp_id = row_value * 8 + column_value;
		if(temp_id > seat_id) seat_id = temp_id; 
	}
	
	printf("The highest seat ID is: %d\n", seat_id);
	
	fclose(fp);
}
