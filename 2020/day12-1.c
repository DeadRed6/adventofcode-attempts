#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *fd;
	fd = fopen("input-12", "r");
	char move;
	int value;
	int x = 0;
	int y = 0;
	short facing = 0;
	while(fscanf(fd, "%c%d\n", &move, &value) != EOF) {
		switch(move) {
			case 'E':
				x += value;
				break;	
			case 'S':
				y -= value;
				break;	
			case 'N':
				y += value;
				break;
			case 'W':
				x -= value;
				break;
			case 'F':
				//If facing east or west ( 0 or 2 ), change the x co-ordinate
				if(facing % 2 == 0)
					x = (facing == 0) ? x + value : x - value;
				else
					y = (facing == 3) ? y + value : y - value;
				break;
			case 'L':
				facing = (facing + 4 - value/90) % 4;	
				break;
			case 'R':
				facing = (facing + value/90) % 4;
				break;
			default:
				break;
		}
	}
	printf("Final x-coordinate: %d\nFinal y-coordinate: %d\nManhattan distance: %d\n", x, y, abs(x) + abs(y));
	
	fclose(fd);
	return 0;
}
