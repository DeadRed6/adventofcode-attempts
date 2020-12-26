#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *fd;
	fd = fopen("input-12", "r");
	char move;
	int value;
	int ship_x = 0;
	int ship_y = 0;
	int waypoint_x = 10;
	int waypoint_y = 1;
	int i; //Used in loops
	int temp; //A temporary co-ordinate holder
	while(fscanf(fd, "%c%d\n", &move, &value) != EOF) {
		switch(move) {
			case 'E':
				waypoint_x += value;
				break;	
			case 'S':
				waypoint_y -= value;
				break;	
			case 'N':
				waypoint_y += value;
				break;
			case 'W':
				waypoint_x -= value;
				break;
			case 'F':
				for(i = 0; i < value; i++) {
					ship_x += waypoint_x;
					ship_y += waypoint_y;
				}
				break;
			case 'L':
				value = 360 - value;	
			case 'R':
				value = value / 90;
				for(i = 0; i < value; i++) {
					temp = waypoint_x;
					waypoint_x = waypoint_y;
					waypoint_y = -temp;
				} 
				break;
			default:
				break;
		}
	}
	printf("Final x-coordinate: %d\nFinal y-coordinate: %d\nManhattan distance: %d\n", ship_x, ship_y, abs(ship_x) + abs(ship_y));
	
	fclose(fd);
	return 0;
}
