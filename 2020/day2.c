#include <stdio.h>

int main(void) {
	int lower;
	int upper;	
	char criterion;
	char password[25];
	FILE *fp;
	fp = fopen("input-2", "r");
	int valid_count = 0;		
	int i;
	int letter_count;
	while(fscanf(fp, "%d-%d %c: %s", &lower, &upper, &criterion, &password) != EOF) {	
		i = 0;
		letter_count = 0;
		while(password[i] != '\0') {
			if(password[i] == criterion) letter_count++; 
			i++;
		}
		if(letter_count >= lower && letter_count <= upper) valid_count++;		
	}
	printf("The number of valid passwords is: %d", valid_count);
	fclose(fp);
}
