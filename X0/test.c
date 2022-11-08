//test.c

#include "wonCheck.c"
#include "stdio.h"
#include "bot.c"


int main(){
	char field[3][3] = {
		{'X', '*', '*'},
		{'*', '*', 'X'},
		{'*', '*', '*'}
	};

	int robot = make_turn(field, 'X', 'O');
	field[robot / 10][robot % 10] = 'X';

	bool is_Won = isWon(field);
	print_field(field);
	printf("%d %d\n", robot, is_Won);
}
