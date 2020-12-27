#include <stdio.h>

//I really don't know the mathematics for this kind of problem
//It doesn't sit right with me to be hardcoding either, but it's midnight and I am tired.
int main(void) {
	
	int timestamp = 1000104;
	int buses[] = {13, 17, 19, 23, 29, 37, 41, 659, 937};
	int i;
	int minutes = 99999999;
	int bus_id = 0;
	int current;
	int current_bus; 
	for(i = 0; i < 9; i++) {
		current = 0;
		current_bus = buses[i];
		while(current < timestamp) {
			current += buses[i];
		}
		if(current < minutes) {
			minutes = current;
			bus_id = buses[i];
		}
	
	}
	printf("Bus ID: %d, Earliest Boarding: %d\nPuzzle Answer: %d\n", bus_id, minutes, bus_id * (minutes - timestamp));
}
