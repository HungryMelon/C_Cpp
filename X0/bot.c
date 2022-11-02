#include "stdio.h"

void print_field(char field[3][3]){
	printf("╔═══╦═══╦═══╗\n");
	printf("║ %c ║ %c ║ %c ║\n", field[0][0], field[0][1], field[0][2]);
	printf("╠═══╬═══╬═══╣\n");
	printf("║ %c ║ %c ║ %c ║\n", field[1][0], field[1][1], field[1][2]);
	printf("╠═══╬═══╬═══╣\n");
	printf("║ %c ║ %c ║ %c ║\n", field[2][0], field[2][1], field[2][2]);
	printf("╚═══╩═══╩═══╝\n");
}

int win_by_one(char may_field[3][3], char who){
	for (int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if (may_field[i][j] == '*' || may_field[i][j] == '-'){
				may_field[i][j] = who;
				print_field(may_field);

				if (isWon(may_field)){
					return (i*10) + j;
				} else {
					may_field[i][j] = '-';
				}
			}
		}
	}
	return -1;
}

int make_turn(char field[3][3], char who, char enemy){
	char may_field[3][3];
	printf("%c\n", who);

/*
	{'X','O'} - Already turned by player/bot before
	'-' - False tryed
	'+' -
*/

	bool isCloned = false;

	//cloning
	if (!isCloned){
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				may_field[i][j] = field[i][j];
			}
		}
	}
	//
	// win by 1 turn
	if(win_by_one(may_field, enemy) != -1) return win_by_one(may_field, enemy); //
	else if(win_by_one(may_field, who) != -1) return win_by_one(may_field, who);
	for (int i = 0; i < 9; i++){ 
		if(
			(i == 0 || i == 2 || i == 6 || i == 8) && 
			(may_field[i/3][i%3] == '*') && (may_field[i/3][i%3] == '-')){
				return ((i / 3) * 10) + (i % 3);
		}
	}
	for (int i = 0; i < 9; i++) if((may_field[i/3][i%3] == '*') && (may_field[i/3][i%3] == '-')) return ((i / 3) * 10) + (i % 3);

}
