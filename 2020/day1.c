#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *ptr = fopen("input-1", "r");

    if(ptr == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    int input_data[200];
    int current_input;
	int i = 0;
    while(fscanf(ptr, "%d", &current_input) != EOF) {
        input_data[i++] = current_input; //Add the number into the array
    }
	
	int j, k;
    for(i = 0; i < 198; i++) {
		for(j = i + 1; j < 199; j++) {
			for(k = j + 1; k < 200; k++) {
				if(input_data[i] + input_data[j] + input_data[k] == 2020) printf("%d\n", input_data[i]*input_data[j]*input_data[k]);
			}
		}    
	}

    return 0;
}

