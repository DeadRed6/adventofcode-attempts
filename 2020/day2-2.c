#include <stdio.h>

int main(void) {
	int first;
	int second;	
	char criterion;
	char password[25];
	FILE *fp;
	fp = fopen("input-2", "r");
	int valid_count = 0;
	short flag = 0;		
	while(fscanf(fp, "%d-%d %c: %s", &first, &second, &criterion, &password) != EOF) {	
			if(password[first - 1] == criterion) {
				flag = password[second - 1] == criterion ? 0 : 1;	
			} else {
				flag = password[second - 1] == criterion ? 1 : 0; 	
			}
			if(flag) valid_count++;
	}
	printf("The number of valid passwords is: %d\n", valid_count);
	fclose(fp);
}
