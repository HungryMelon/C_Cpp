#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "wonCheck.c"
// ═ ║ ╔ ╚ ╗ ╝ ╠ ╣ ╩ ╦ ╬

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
	char score[] = {0, 0}; // 0 - X, 1 - 0
	char field[3][3] = {
		{'*', '*', '*'},
		{'*', '*', '*'},
		{'*', '*', '*'}
	};
	bool whoIswho = true; // X - true, 0 - false
	int winner = 0; //-1 : 0 : 1 - X, NONE, 0
	int counter = 0;

	while(true){ //global loop
		

		char who = whoIswho == true ? 'X' : '0'; //who move now
		int pos = 0;
		//io:
		if (winner != 0){
			printf("[X]: %d %c\n", score[0], (winner == -1 ? '<' : ' '));
			printf("[0]: %d %c\n", score[1], (winner == 1 ? '<' : ' '));
		} else {
			printf("[X]: %d \n[0]: %d\n", score[0], score[1]);
		}


		print_field(field);

		printf("Ход [%c]: ", who);

		scanf("%d", &pos);
		//
		if ((pos % 10 > 0 || pos % 10 <= 3) && (pos / 10 > 0 || pos / 10 <= 3) && field[(pos / 10)-1][(pos % 10)-1] == '*'){
			whoIswho = !whoIswho;
			field[(pos / 10)-1][(pos % 10)-1] = who;

			counter++;

			if (counter == 9) {
				for (int i = 0; i < 3; i++){
					for (int j = 0; j < 3; j++){
						field[i][j] = '*';
						winner = 0;
					}
				}
			}
		}
		bool is_Won = isWon(field);

		if (is_Won){
			score[whoIswho]++;
			counter = 0;
			winner = (!whoIswho == true ? -1 : 1);
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					field[i][j] = '*';
					whoIswho = !whoIswho;
				}
			}
		}
		system("clear");
		printf("+----+\ndebug info \nprevious turn: \nis won: %d\nwho: %c\ncounter: %d\nwinner: %d\n+----+\n", is_Won, who, counter, winner); //debug info
	}
	return 0;
}
