//test.c

#include "wonCheck.c"
#include "stdio.h"
#include "bot.c"

void print_field(char field[3][3]){
	printf("╔═══╦═══╦═══╗\n");
	printf("║ %c ║ %c ║ %c ║\n", field[0][0], field[0][1], field[0][2]);
	printf("╠═══╬═══╬═══╣\n");
	printf("║ %c ║ %c ║ %c ║\n", field[1][0], field[1][1], field[1][2]);
	printf("╠═══╬═══╬═══╣\n");
	printf("║ %c ║ %c ║ %c ║\n", field[2][0], field[2][1], field[2][2]);
	printf("╚═══╩═══╩═══╝\n");
}

int main(){
	char field[3][3] = {
		{'X', '*', 'X'},
		{'*', '*', '*'},
		{'*', '*', '*'}
	};

	int robot = make_turn(field, 'X', 'O');
	field[robot / 10][robot % 10] = 'X';

	bool is_Won = isWon(field);
	print_field(field);
	printf("%d %d\n", robot, is_Won);

	return 0;
}

