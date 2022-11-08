/*
field:
   0 1 2
 0 * * * 
 1 * * * 
 2 * * *

Win is posible if field look like:
	1: j0 == j1 == j2 in any i
	2: i0 == i1 == i2 in any j = ji 
	3: i0j0 == i1j1 == i2j2
	4: i0j2 == i1j1 == i2j0
*/
int isWon(char field[3][3]){
	for (int i = 0; i < 3; i++){ // 1
		if ((field[i][0] == field[i][1]) && (field[i][1] == field[i][2]) && (field[i][0] != '*' && field[i][0] != '-')) return true;
	}
	for (int i = 0; i < 3; i++){ // 2
		if ((field[0][i] == field[1][i]) && (field[1][i] == field[2][i]) && (field[0][i] != '*' && field[0][i] != '-')) return true;
	}
	if ((field[0][0] == field[1][1]) && (field[1][1] == field[2][2]) && ((field[0][0] != '*') && (field[0][0] != '-'))) return true; //3
	if ((field[0][2] == field[1][1]) && (field[1][1] == field[2][0]) && ((field[0][2] != '*') && (field[0][2] != '-'))) return true; //4
	return false;
}
